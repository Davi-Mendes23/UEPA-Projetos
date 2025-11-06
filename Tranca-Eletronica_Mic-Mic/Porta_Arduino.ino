/*
=======================================================================
                    TRANCA ELETRÔNICA ARDUINO
=======================================================================
*/

// =======================================================================
// BIBLIOTECAS
// =======================================================================
#include <Wire.h> 
#include <LiquidCrystal_I2C.h> 
#include <Keypad.h> 
#include <EEPROM.h> 
#include <string.h> 
#include <SPI.h> 
#include <MFRC522.h>

// =======================================================================
// CONSTANTES E DEFINIÇÕES
// =======================================================================
#define releFechadura A1 
#define BB A2
#define SS_PIN 10 
#define RST_PIN A0
#define tamanho_senha 6
#define tempo 200 
#define tempoAberto 2000

// =======================================================================
// VARIÁVEIS GLOBAIS
// =======================================================================
char senha[7] = "ABC123"; // Definição da senha 
char coletado[7]; 
unsigned long time = millis(); 
unsigned long lastTime = time;  

// =======================================================================
// CONFIGURAÇÃO DO TECLADO
// =======================================================================
const byte LINHAS = 4; 
const byte COLUNAS = 4; 
char digitos[LINHAS][COLUNAS] = { 
  {'1','2','3','A'}, 
  {'4','5','6','B'}, 
  {'7','8','9','C'}, 
  {'*','0','#','D'} 
}; 
byte pinosLinha[LINHAS] = { 9, 8, 7, 6 }; 
byte pinosColuna[COLUNAS] = { 5, 4, 3, 2 }; 
Keypad keypad = Keypad( makeKeymap(digitos), pinosLinha, pinosColuna, LINHAS, COLUNAS ); 

// =======================================================================
// CONFIGURAÇÃO DE DISPOSITIVOS
// =======================================================================
// Tela LCD 
LiquidCrystal_I2C lcd_1(0x27, 16,2); 

// Leitor RFID 
MFRC522 mfrc522(SS_PIN, RST_PIN); 

/**** 
MAPA DA MEMORIA EEPROM 

  de 0 a 6 -> senha[7]; 
  7 -> controlador da senha; 
  8 -> GAP --------------------- 
  9 -> Numero de cartões; 
  10 -> cartão um; 
  de 11 a 14 -> uid do cartão 
  15 - cartão dois... 
  ... 
****/ 

// =======================================================================
// CONFIGURAÇÃO INICIAL (SETUP)
// =======================================================================
void setup() { 
  Serial.begin(9600); 

  // Carrega a senha da EEPROM se já foi configurada
  if (EEPROM.read(7) == 1){ 
    for (int i = 0; i < tamanho_senha; i++) { 
      senha[i] = EEPROM.read(i); 
    } 
  } 

  // Inicializa o LCD 
  lcd_1.init();
  //lcd_1.begin(16,2);
  lcd_1.backlight(); 

  // Inicializa o SPI bus e RFID 
  SPI.begin();
  mfrc522.PCD_Init();

  // Define os pinos de saída do arduino 
  pinMode(releFechadura, OUTPUT); 
  pinMode(BB, OUTPUT); 

  // Tranca a Porta inicialmente
  trancado(true); 
} 

// =======================================================================
// LOOP PRINCIPAL
// =======================================================================
void loop() {
  abrir();
} 

// =======================================================================
// FUNÇÕES PRINCIPAIS DE CONTROLE
// =======================================================================

void trancado(boolean fechadura) { 
  if (fechadura) { 
    digitalWrite(releFechadura, LOW); // Importante: para uso com rele de acionamento da fechadura LOW deve ser subsstituído por HIGH 
    aviso("Porta Fechada"); 
  } else { 
    digitalWrite(releFechadura, HIGH); // Importante: para uso com rele de acionamento da fechadura HIGH deve ser subsstituído por LOW 
    aviso("Porta Aberta"); 
    
    delay(tempoAberto); 
    trancado(true); // Tranca a porta novamente  
  } 
} 

void abrir() { 
  lcd_1.clear(); 

  escrever(0, "Digite a Senha"); 
  escrever(1, "[------]"); 

  coletar(); 

  if (strcmp(coletado, "------") == 0) return; 

  if(strcmp(coletado, senha) != 0){ 
    aviso("Senha Errada"); 
    return; 
  }  

  aviso("Senha Correta"); 
  menu(); 
} 

// =======================================================================
// SISTEMA DE MENU E NAVEGAÇÃO
// =======================================================================

void menu() { 
  byte pagina = 1; 
  while(pagina >= 1){ 
    lcd_1.clear(); 
    escrever(0, "1-Abrir a Porta"); 
    escrever(1, "2-Configuracao"); 

    switch (escolha()){ 
      case 1:  
        trancado(false); 
        return;
        break; 
      case 2: 
        pagina = 2; 
        while(pagina >= 2){ 
          lcd_1.clear(); 
          escrever(0, "1-Cartao"); 
          escrever(1, "2-Mudar Senha"); 
          switch (escolha()){ 
            case 3: 
              pagina = 1; 
              break; 
            case 1: 
              pagina = 3; 
              while(pagina >= 3){ 
                lcd_1.clear(); 
                escrever(0, "1-Registrar"); 
                escrever(1, "2-Apagar"); 
                switch (escolha()){ 
                  case 3: 
                    pagina = 2; 
                    break; 
                  case 1: 
                    registrarCard(); 
                    break; 
                  case 2: 
                    apagarCard(); 
                    break; 
                  default: 
                    return; 
                } 
              } 
              break; 
            case 2: 
              mudar(); 
              break; 
            default: 
              return; 
          } 
        } 
        break; 
      default: 
        return; 
    } 
  } 
} 

int escolha(){ 
  byte escolheu = 0; 
  lastTime = time; 
  while (escolheu==0 && time - lastTime < 40000) { 
    time = millis(); 
    char digito = keypad.getKey(); // Coleta oque está sendo digitado 
    if (digito == '1'){ 
      buzzer(tempo); 
      escolheu = 1; 
    }  
    if (digito == '2'){ 
      buzzer(tempo); 
      escolheu = 2; 
    } 
    if (digito == '*'){ 
      buzzer(tempo); 
      escolheu = 3; 
    } 
    if (digito == '#'){ 
      buzzer(tempo); 
      escolheu = -1; 
    } 
  } 
  lcd_1.clear(); 
  return escolheu; 
} 

// =======================================================================
// FUNÇÕES DE ENTRADA DE DADOS
// =======================================================================

void coletar() { 
  int position = 0; 
  strcpy(coletado, "------"); 

  lastTime = time; 

  while(time - lastTime < 20000){ 

    if(lerCard()) break; 

    if (position == 0) {lastTime = time;} 

    time = millis(); 

    char digito = keypad.getKey(); // Coleta oque está sendo digitado 

    if (digito) { 
      buzzer(tempo); 

      if(digito == '*'){ 
        if (position>0) position--; 
        coletado[position] = '-'; 
        escrever(1, coletado );
      }else { 
        if(digito == '#') break; 
        coletado[position] = digito; // Armazena a tentativa 
        escrever(1, coletado);
        position++; 
      } 
    } 

    if(position == tamanho_senha) return; 
  } 

  strcpy(coletado, "------");
} 

// =======================================================================
// FUNÇÕES DE GERENCIAMENTO DE SENHA
// =======================================================================

void mudar() { 
  lcd_1.clear(); 

  escrever(0, "A Nova Senha"); 
  escrever(1, "[------]"); 

  char novaSenha[7]; 
  char repitaSenha[7]; 

  coletar(); 

  strcpy (novaSenha, coletado); 

  if (strcmp(coletado, "------") == 0)  return;  

  escrever(0, "Repita a Senha"); 
  escrever(1, "[------]"); 

  coletar(); 

  if (strcmp(coletado, "------") == 0)  return; 

  if (strcmp(novaSenha, coletado)!= 0){ 
    aviso("Falha!", "Senhas Diferentes"); 
  } else { 
    aviso("Sucesso!", "Senha Mudada"); 

    for (int i = 0; i < tamanho_senha; i++) { 
      EEPROM.write(i, novaSenha[i]); 
      senha[i] = EEPROM.read(i); 
    } 
    EEPROM.write(7, 1); 
  } 
} 

// =======================================================================
// FUNÇÕES DE GERENCIAMENTO DE CARTÕES RFID
// =======================================================================

bool lerCard(){ 
  if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) { 
    if (checkUID(mfrc522.uid.uidByte)) { 
      trancado(false); 
      return true; 
    } 
  } 
  return false; 
}

void listar(byte* lista_saida){
  byte registrados = EEPROM.read(9);
  byte encontrados = 0;

  if(registrados <= 0) return; // Retorna se nenhum card registrado

  for (byte i = 0; i < 150; i++) {
    byte value = EEPROM.read((i * 5) + 10); 

    if (value > 0 && value < 255) {
      lista_saida[encontrados] = value;
      encontrados++;

      if (encontrados == registrados) {
        break;
      }
    }
  }
}

byte nomeando(){
  byte registrados = EEPROM.read(9);
  byte lista[registrados];
  listar(lista);

  for (int i = 0; i < registrados; i++){
    if ( i+1 != lista[i]) return i+1;
  }

  return registrados + 1;
}

void registrarCard(){ 
  lcd_1.clear(); 
  escrever(0, "Aproxime o Card:"); 
  char digito = keypad.getKey(); // Coleta oque está sendo digitado 
  while (digito != '#' && EEPROM.read(9) < 150){ 
    digito = keypad.getKey();
    if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
      byte* uid = mfrc522.uid.uidByte;
      byte nome = nomeando();

      EEPROM.write((EEPROM.read(9)*5)+10, (int) nome ); 
      for (byte j = 0; j < 4; j++){ 
        EEPROM.write((EEPROM.read(9)*5)+11+j, uid[j]); 
      } 
      EEPROM.write(9, EEPROM.read(9)+1); 
      aviso(mensagem("Card %d Guardado", nome)); 
      return; 
    } 
  } 
} 

void apagarCard(){ 
  lcd_1.clear(); 
  byte registrados = EEPROM.read(9);
  if(registrados <= 0) {
    aviso("Sem registros.");
    return;}
  
  byte lista[registrados];
  listar(lista);

  char input;
  int exibido = 0;

  escrever (0, mensagem("Apagar: %d", lista[exibido]));
  escrever (1, "B: < A: > #: OK");

  while ((input = keypad.getKey()) != '#') {
    if (input){ 
      buzzer(tempo);
      if(input == '*') return;
      if (input == 'A' && exibido < EEPROM.read(9)-1) {
        exibido++;
      } else if (input == 'B' && exibido>0) {
        exibido--;
      }
      lcd_1.clear();
      escrever (0, mensagem("Apagar: %d", lista[exibido]));
      escrever (1, "B: < A: > #: OK");
    }
  } 

  for (int j = 10; j < 150*5+10; j+=5 ){
    if(EEPROM.read(j) == lista[exibido]){ 
      for (byte p = 1; p < 5; p++){ 
        EEPROM.write(j+p, 255); 
      } 
      EEPROM.write(j, 255); 
      EEPROM.write(9, EEPROM.read(9)-1); 
      lcd_1.clear(); 
      aviso(mensagem("Card %d Apagado", lista[exibido])); 
      return; 
    } 
  }
} 

bool checkUID(byte* uid) { 
  for (byte i = 0; i < 150; i++) {
    if (EEPROM.read(i) == 255) continue;
    for (byte j = 0; j < 4; j++){ 
      if (uid[j] != EEPROM.read((i*5)+11+j)) break; 
      if (j == 3) {
        aviso(mensagem("Card %d", EEPROM.read((i*5)+10)), "Identificado");
        return true;
      }
    } 
  } 
  return false; 
} 

// =======================================================================
// FUNÇÕES DE INTERFACE E UTILIDADES
// =======================================================================

void buzzer(int time){ 
  digitalWrite(BB, HIGH); 
  delay(time); 
  digitalWrite(BB, LOW); 
} 

char *mensagem(const char *format, ...) { 
  static char buffer[16]; 
  va_list args; 
  va_start(args, format); 
  vsnprintf(buffer, 16, format, args); 
  va_end(args); 
  return buffer; 
}

void escrever(int linha, char* texto){ 
  lcd_1.setCursor(ceil((16-strlen(texto))/2.0), linha); 
  lcd_1.print(texto); 
} 

void aviso(char* primeira_mensagem) {
  lcd_1.clear();
  escrever(0, primeira_mensagem);
  buzzer(500);
  delay(1000);
  lcd_1.clear();
}

void aviso(char* primeira_mensagem, char* segunda_mensagem) {
  lcd_1.clear();
  escrever(0, primeira_mensagem);
  escrever(1, segunda_mensagem);
  buzzer(500);
  delay(1000);
  lcd_1.clear();
}
}
