# Tranca Eletrônica com Arduino
Este projeto apresenta o desenvolvimento de uma tranca eletrônica controlada por Arduino, que utiliza teclado matricial, display LCD, relé e leitor RFID (MFRC522) para controle de acesso seguro. O sistema permite abrir a porta mediante a digitação de uma senha ou pela aproximação de um cartão RFID previamente registrado.

- O código implementa as seguintes funcionalidades principais:
  - Validação de senha: Entrada via teclado com seis caracteres.
  - Gerenciamento de senha: Opção para alterar a senha armazenada na EEPROM.
  - Controle de acesso com RFID: Registro, identificação e exclusão de cartões RFID, também armazenados na EEPROM.
  - Interface com usuário: Exibição de mensagens no display LCD e emissão de sinais sonoros via buzzer.
  - Menu de navegação: Permite abrir a porta, configurar cartões e alterar a senha.
  - Segurança: Bloqueio automático após tempo determinado e centralização de dados na EEPROM.

O funcionamento do sistema baseia-se em uma lógica de autenticação que, após a validação da senha ou cartão, ativa o relé para destravar a porta temporariamente e, em seguida, religa a tranca.
