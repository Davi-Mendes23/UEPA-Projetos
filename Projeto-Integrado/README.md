# 📊 Análise Comparativa de LLMs na Elaboração de Resumos de Editais Públicos

[![Status](https://img.shields.io/badge/Status-Em%20Desenvolvimento-yellow)]()
[![Universidade](https://img.shields.io/badge/UEPA-Engenharia%20de%20Software-blue)]()

> Uma abordagem sistemática utilizando estratégias de engenharia de prompt para avaliar a eficácia de diferentes LLMs na sumarização abstrativa de editais públicos.

## 📖 Sobre o Projeto

Este projeto de pesquisa acadêmica investiga a performance de quatro modelos de linguagem (ChatGPT, Gemini, DeepSeek e Copilot) na geração de resumos estruturados de editais públicos, comparando diferentes técnicas de engenharia de prompt.

### 🎯 Problema de Pesquisa

**Qual LLM disponível ao público é mais confiável e melhor performa no resumo de editais aplicando diferentes técnicas de engenharia de prompt considerando critérios de coerência e integridade da informação?**

## 🔬 Metodologia

### 1. Coleta de Dados
- **5-10 editais públicos** de diferentes categorias (concursos, licitações, bolsas, ingressos)
- Armazenamento e catalogação estruturada

### 2. Estratégias de Prompt

Três abordagens distintas foram desenvolvidas:

| Abordagem | Descrição |
|-----------|-----------|
| **Simplificada** | Simula usuário comum sem conhecimento técnico |
| **Chain-of-Thought** | Processo de raciocínio passo a passo |
| **Extrativa-Abstrativa** | Combinação de sumarização extrativa seguida de abstrativa |

### 3. Modelos Avaliados

- **ChatGPT** (GPT-4o)
- **Gemini** (2.0 flash)
- **DeepSeek** (V3)
- **Copilot**

### 4. Critérios de Avaliação

Baseados em metodologias consolidadas (Fabbri et al., 2021; Tabosa et al., 2020):

- ✅ **Coerência**: Estrutura e organização do resumo
- ✅ **Consistência**: Alinhamento factual com o documento original
- ✅ **Fluência**: Qualidade gramatical e estrutural
- ✅ **Relevância**: Seleção apropriada de conteúdo importante

### 5. Processo de Avaliação

```
Edital → Prompt → LLM → Resumo → Avaliação Humana → Classificação
```

- **Avaliadores**: 3 voluntárias (acadêmicas de licenciatura)
- **Escala**: Likert (1-5) para cada critério
- **Ferramenta**: Google Forms com formulários estruturados
- **Análise**: Média das avaliações por Google Planilhas

## 📊 Resultados Esperados

1. **Prompts eficientes** para diferentes perfis de usuários
2. **Base de dados de resumos avaliados** para pesquisas futuras
3. **Ranking definitivo** de modelos, prompts e combinações modelo/prompt

## 🎓 Estrutura do Trabalho

```
1. Introdução
   1.1. Justificativa
   1.2. Objetivos
   1.3. Organização do texto
2. Metodologia
   2.1. Coleta dos editais
   2.2. Definição dos prompts
   2.3. Produção dos resumos
   2.4. Avaliação dos resumos
3. Resultados e discussões
   3.1. Classificação das avaliações
   3.2. Comparação das avaliações
4. Conclusões
5. Referências
6. Apêndices
```

## 📅 Cronograma

| Etapa | Mês 1 | Mês 2 | Mês 3 | Mês 4 | Mês 5 | Mês 6 |
|-------|-------|-------|-------|-------|-------|-------|
| Coleta dos editais | ✓ | | | | | |
| Construção dos prompts | ✓ | ✓ | | | | |
| Geração dos resumos | | ✓ | ✓ | | | |
| Avaliação dos resumos | | | ✓ | ✓ | ✓ | |
| Classificação das avaliações | | | | | ✓ | |
| Comparação e análise | | | | | | ✓ |

## 💰 Orçamento

**R$ 0,00** - Utilização exclusiva de versões gratuitas dos modelos

## 👥 Equipe

- **Davi Costa Mendes da Silva** - Discente
- **Ryan Souza Santana** - Discente
- **Prof. Dr. Eng. Ítalo Flexa Di Paolo** - Orientador

## 📚 Referências Principais

- Fabbri et al. (2021) - SummEval
- Zhang, Liu, Zhang (2023) - Extractive Summarization via ChatGPT
- Son, Won, Lee (2025) - Prompt Engineering Techniques
- Shen et al. (2023) - LLMs as Evaluators

## 📄 Licença

Este é um projeto acadêmico desenvolvido na Universidade do Estado do Pará (UEPA) - Centro de Ciências Naturais e Tecnologia (CCNT).

---

**Elaborado em**: 27/05/2025  
**Área de conhecimento**: Sistemas de Informação
