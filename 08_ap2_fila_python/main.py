import os

sair = 0
fila = []

while sair != 1:
    entrada = int(input('''
        Selecione:
         [1] Adicionar número
         [2] Excluir número
         [0] Sair \n 
        '''))
        
    if entrada == 1:
        recebido = input('O que deseja adicionar? ')
        fila.append(recebido)
        os.system('clear') or None
        print(fila)
    
    if entrada == 2:
        if not fila:
            os.system('clear') or None
            print("A fila está vazia.")
        else:
            fila.pop(0)
            if not fila:
                os.system('clear') or None
                print("A fila está vazia.")
            else:
                os.system('clear') or None
                print(fila)
        
    if entrada == 0:
        sair = 1