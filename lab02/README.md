# Lab02

|NOME                           |TIA                 |
|-------------------------------|--------------------|
|Filipe Costa Pereira           |32106521            |
|Maisa Folgueral                |32121385            |
|Raphael Vinicius Costa Alencar |32195451            |

### Como compilar o programa na plataforma disponibilizada
```
gcc nome_arquivo.c -o nome_arquivo
```

### Como executar o programa
```
time ./nome_arquivo
```

### Como comprovar que os resultados propostos foram alcançados
Ao compara os código de multiprocessado e serial através do comando time do Linux, podemos verificar que o multiprocessado tende a ser mais lento. <br/>

Execução serial:
```
real    0m1.280s
user    0m0.001s
sys     0m0.000s
```

Execução multiprocessado:
```
real    0m1.496s
user    0m0.001s
sys     0m0.000s
```
