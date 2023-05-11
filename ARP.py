# Aluno: Luiz Filipe Neuwirth - 2111287
# Data: 11/05/2023

# Definição da estrutura para armazenar as informações do paciente
class Paciente:
    def _init_(self, id, nome, idade, endereco, cidade, estado, data):
        self.id = id
        self.nome = nome
        self.idade = idade
        self.endereco = endereco
        self.cidade = cidade
        self.estado = estado
        self.data = data

# Função para realizar a busca sequencial pelo intervalo de meses de jan/22 e fev/22
def busca_sequencial(pacientes):
    encontrados = 0
    for paciente in pacientes:
        # Verifica se a data do paciente está dentro do intervalo de meses de jan/22 e fev/22
        if paciente.data.startswith('01/22') or paciente.data.startswith('02/22'):
            encontrados += 1
            print(f'Paciente {encontrados}:')
            print(f'ID: {paciente.id}')
            print(f'Nome: {paciente.nome}')
            print(f'Idade: {paciente.idade}')
            print(f'Endereço: {paciente.endereco}')
            print(f'Cidade: {paciente.cidade}')
            print(f'Estado: {paciente.estado}')
            print(f'Data de registro: {paciente.data}')
    if encontrados == 0:
        print('Nenhum paciente encontrado no intervalo de meses de jan/22 e fev/22.')

# Função auxiliar para comparar dois pacientes pelo ID (utilizada na ordenação para a busca binária)
def comparar_id(paciente):
    return paciente.id

# Função para realizar a busca binária pelo intervalo de meses de jan/22 e fev/22
def busca_binaria(pacientes):
    # Ordena a lista de pacientes pelo ID antes de realizar a busca binária
    pacientes.sort(key=comparar_id)
    encontrados = 0
    esquerda = 0
    direita = len(pacientes) - 1
    while esquerda <= direita:
        meio = (esquerda + direita) // 2
        # Verifica se a data do paciente está dentro do intervalo de meses de jan/22 e fev/22
        if pacientes[meio].data.startswith('01/22') or pacientes[meio].data.startswith('02/22'):
            encontrados += 1
            print(f'Paciente {encontrados}:')
            print(f'ID: {pacientes[meio].id}')
            print(f'Nome: {pacientes[meio].nome}')
            print(f'Idade: {pacientes[meio].idade}')
            print(f'Endereço: {pacientes[meio].endereco}')
            print(f'Cidade: {pacientes[meio].cidade}')
            print(f'Estado: {pacientes[meio].estado}')
            print(f'Data de registro: {pacientes[meio].data}')
            esquerda = meio + 1
        elif comparar_id(pacientes[meio]) < comparar_id(pacientes[direita]):
            esquerda = meio + 1
        else:
            direita = meio - 1
    if encontrados == 0:
        print('Nenhum paciente encontrado no intervalo de meses de jan/22 e fev/22.')