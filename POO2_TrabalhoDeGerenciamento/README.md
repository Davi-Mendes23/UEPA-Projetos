# 📦 Sistema de Gerenciamento de Estoque

> Projeto acadêmico desenvolvido na disciplina de Programação Orientada a Objetos II (POO2) - Universidade do Estado do Pará (UEPA)

## 📋 Sobre o Projeto

Sistema de gerenciamento de estoque desenvolvido em Java, aplicando conceitos avançados de Programação Orientada a Objetos. O projeto implementa operações CRUD (Create, Read, Update, Delete) para gerenciamento de produtos, fornecedores e insumos, com interface gráfica intuitiva utilizando Java Swing.

## ✨ Funcionalidades

### 🏭 Gerenciamento de Produtos
- ✅ Cadastro de produtos
- 📝 Edição de informações
- 🗑️ Exclusão de produtos
- 🔍 Listagem e busca de produtos
- 📊 Visualização detalhada

### 👥 Gerenciamento de Fornecedores
- ✅ Cadastro de fornecedores
- 📝 Atualização de dados
- 🗑️ Remoção de fornecedores
- 📋 Listagem completa

### 🔧 Gerenciamento de Insumos
- ✅ Cadastro de insumos
- 📝 Controle de estoque
- 🗑️ Exclusão de insumos
- 📊 Relatórios de insumos

### 🎨 Interface Gráfica
- 💻 Interface amigável com Java Swing
- 📱 Telas responsivas
- 🎯 Navegação intuitiva
- 🖼️ Ícones personalizados

## 🛠️ Tecnologias Utilizadas

- **Linguagem:** Java
- **Interface Gráfica:** Java Swing
- **Padrão de Projeto:** MVC (Model-View-Controller)
- **Build Tool:** Gradle
- **IDE:** Visual Studio Code / Apache NetBeans IDE

## 📁 Estrutura do Projeto

```
POO2_TrabalhoDeGerenciamento/
│
├── build/                          # Arquivos compilados
│   ├── classes/
│   └── tmp/
│
├── Dao/                            # Camada de Acesso a Dados
│   ├── ProdutosDAO.java
│   └── UsuariosDAO.java
│
├── factory/                        # Padrão Factory
│   ├── ConnectionFactory.class
│   └── HashUtil.class
│
├── jar/                            # Bibliotecas externas
│
├── tela/                           # Interfaces Gráficas (Views)
│   ├── TelaCadastroProduto1.java
│   ├── TelaCadastroProduto2.java
│   ├── TelaCadastroProduto3.java
│   ├── TelaCadastroProduto4.java
│   ├── TelaCadastroBundle.java
│   ├── TelaCadastroBundle2.java
│   ├── TelaCadastroInsumo1.java
│   ├── TelaCadastroInsumo2.java
│   ├── TelaCadastroInsumo3.java
│   ├── TelaCadastroInsumo4.java
│   ├── TelaGerenciarInsumo1.java
│   ├── TelaGerenciarInsumo2.java
│   ├── TelaGerenciarInsumo3.java
│   ├── TelaGerenciarInsumo4.java
│   ├── TelaGerenciarProduto1.java
│   ├── TelaGerenciarProduto2.java
│   ├── TelaGerenciarProduto3.java
│   ├── TelaGerenciarProduto4.java
│   ├── TelaBiologicos.java
│   ├── TelaInsumoId.java
│   ├── TelaLogin.java
│   └── TelaLoginAux.java
│
├── img/                            # Recursos visuais
│   ├── icons_gerillha_utf8.png
│   ├── icons_principal(1)_utf8.png
│   ├── icons_usuario_utf8.png
│   └── logo_uepa_poo2(1).png
│
├── modelo/                         # Modelos de dados
│   └── Produtos.java
│
├── relatorios/                     # Sistema de relatórios
│   └── RelatoriosProdutos.java
│
├── config.properties               # Configurações do projeto
├── build.xml                       # Configuração Ant
├── manifest.mf                     # Manifest do JAR
├── gradle.properties               # Propriedades Gradle
├── gradlew                         # Gradle Wrapper (Unix)
├── gradlew.bat                     # Gradle Wrapper (Windows)
├── build.gradle                    # Script de build Gradle
└── README.TXT                      # Documentação original
```

## 🚀 Como Executar

### Pré-requisitos

- Java JDK 8 ou superior
- Gradle (ou use o wrapper incluído)
- IDE Java (recomendado: IntelliJ IDEA, Eclipse ou VSCode)

### Passos para execução

1. **Clone o repositório:**
```bash
git clone https://github.com/Davi-Mendes23/UEPA-Projetos.git
cd UEPA-Projetos/POO2_TrabalhoDeGerenciamento
```

2. **Compile o projeto com Gradle:**
```bash
# Linux/Mac
./gradlew build

# Windows
gradlew.bat build
```

3. **Execute a aplicação:**
```bash
# Linux/Mac
./gradlew run

# Windows
gradlew.bat run
```

**OU** abra o projeto em sua IDE favorita e execute a classe principal.

## 💡 Conceitos de POO Aplicados

- ✅ **Encapsulamento:** Proteção de dados através de modificadores de acesso
- ✅ **Herança:** Reutilização de código através de hierarquia de classes
- ✅ **Polimorfismo:** Flexibilidade na implementação de métodos
- ✅ **Abstração:** Separação de responsabilidades em camadas (MVC)
- ✅ **Padrões de Projeto:** Factory, DAO (Data Access Object)

## 🎓 Padrões Implementados

### MVC (Model-View-Controller)
- **Model:** Classes em `modelo/` e `Dao/`
- **View:** Interfaces gráficas em `tela/`
- **Controller:** Lógica de negócio distribuída

### DAO (Data Access Object)
- Abstração do acesso a dados
- Separação da lógica de persistência

### Factory Pattern
- `ConnectionFactory`: Gerenciamento de conexões
- `HashUtil`: Utilitários para segurança
- 
## 📝 Licença

Este projeto é um trabalho acadêmico desenvolvido para fins educacionais na Universidade do Estado do Pará (UEPA).

## 🤝 Contribuindo

Este é um projeto acadêmico, mas sugestões e melhorias são bem-vindas! Sinta-se à vontade para:

1. Fazer um Fork do projeto
2. Criar uma branch para sua feature (`git checkout -b feature/NovaFuncionalidade`)
3. Commit suas mudanças (`git commit -m 'Adiciona nova funcionalidade'`)
4. Push para a branch (`git push origin feature/NovaFuncionalidade`)
5. Abrir um Pull Request

## 📧 Contato

Para dúvidas ou sugestões sobre o projeto, entre em contato através do GitHub.

---

⭐ Se este projeto foi útil para você, considere dar uma estrela no repositório!
*Programação Orientada a Objetos II*
