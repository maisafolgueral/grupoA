# Lab03

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

Calculo Speedup:
```
Speedup = Tempo em 1 CPU / Tempo. em p CPUs
Speeduo = 0.003 / 0.027 = 0,1111111111111111...
```
