# Barbearia API

Backend de um sistema de gerenciamento e agendamento para barbearias, desenvolvido como uma API RESTful.

## Sobre o Projeto

Este software está sendo construído como projeto acadêmico correspondente ao 3º semestre da faculdade. O objetivo principal é aplicar os conceitos de programação no desenvolvimento de uma solução real e funcional para uma barbearia local, automatizando o controle de clientes e a reserva de horários.

A arquitetura do sistema é separada em duas frentes: uma API no backend e uma aplicação cliente no frontend. Este repositório contém exclusivamente o código-fonte do servidor.

## Stack Tecnológico

* **Linguagem:** C++, JavaScript, HTML, CSS
* **Framework Web:** Drogon
* **Banco de Dados:** PostgreSQL
* **Ferramentas:** CLion, CMake, VSCode

## Funcionalidades e Estrutura

Atualmente, o escopo do projeto cobre os seguintes módulos:

* **Módulo de Clientes:** Operações de CRUD (Create, Read, Update, Delete) para gestão da base de clientes.
* **Módulo de Agendamento:** Sistema de reserva de horários com validação de disponibilidade e prevenção de conflitos de agenda via constraints no banco de dados.
* **Painel de Atendimento (Em desenvolvimento):** Roteamento de serviços (tipo de corte) e identificação do profissional (barbeiro) responsável.

## Observação

Por se tratar de um projeto acadêmico em fase de desenvolvimento ativo, a modelagem de dados e as rotas da API estão passando por refatorações frequentes. A lógica de negócios está sendo centralizada no banco de dados relacional sempre que possível para garantir a integridade dos dados.

## Desenvolvedores

* **Vitor:** Backend (C++, Drogon, Banco de Dados)
* **Thiago:** Frontend (Interface, Integração com a API, JavaScript, HTML, CSS, UX)
