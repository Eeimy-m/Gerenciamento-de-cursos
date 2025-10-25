# Gerenciamento de cursos

Esse projeto segue a proposta de um sistema backend que gerencia uma escola de cursos.

### Dados dos alunos:

    CPF, nome, data de nascimento, sexo, e-mails e números de telefone.

    O CPF é uma chave única, ou seja, o programa possui uma verificação que não permite o cadastro de um cpf que já se encontra no sistema.

    Essa verificação é feita na função de nome `<verificarCPF>`.

### Dados dos cursos:

    Código, carga horária, preço e descrição.

    O código funcionará igualmente ao cpf. A verificação é feita pela função `<verificarCodigo>`.

## Informações técnicas:

Os dados manipulados serão alocados dinamicamente na memória e gravados em arquivos de texto.