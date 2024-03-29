# Lab04 (Parte 1)

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
Ao comparar os códigos de multiprocessado e serial através do comando time do Linux, podemos verificar que o multiprocessado foi executado de forma mais lenta. <br/>

Execução serial:
```
real    0m0.003s
user    0m0.003s
sys     0m0.000s
```

Execução multiprocessado:
```
real    0m0.027s
user    0m0.005s
sys     0m0.035s
```

Cálculo Speedup:
```
Speedup = Tempo em 1 CPU / Tempo. em p CPUs
Speedup = 0.003 / 0.027 = 0,1111111111111111...
```
