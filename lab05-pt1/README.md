# Lab05 (Parte 1)

|NOME                           |TIA                 |
|-------------------------------|--------------------|
|Filipe Costa Pereira           |32106521            |
|Maisa Folgueral                |32121385            |
|Raphael Vinicius Costa Alencar |32195451            |

### Como compilar o programa na plataforma disponibilizada
```
gcc nome_arquivo.c -o nome_arquivo -fopenmp -lm
```

### Como executar o programa
```
time ./nome_arquivo
```

### Como comprovar que os resultados propostos foram alcançados
Ao comparar os códigos de multiprocessado e serial através do comando time do Linux, podemos verificar que o multiprocessado foi executado de forma mais lenta. <br/>

<img src="https://github.com/maisafolgueral/grupoA/blob/main/lab05-pt1/print.PNG?raw=true"/> <br/>

Cálculo Speedup:
```
Speedup = Tempo em 1 CPU / Tempo. em p CPUs
Speedup = 0.001/0.004 = 0.25

```

