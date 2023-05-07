# Projeto Tartaruga

|NOME                           |TIA                 |
|-------------------------------|--------------------|
|Filipe Costa Pereira           |32106521            |
|Maisa Folgueral                |32121385            |
|Raphael Vinicius Costa Alencar |32195451            |

### Como compilar o programa na plataforma disponibilizada
Serial:
<br/>
```
gcc nome_arquivo.c -o nome_arquivo
```
Paralelo:
<br/>
```
gcc nome_arquivo.c -o nome_arquivo -fopenmp -lm
```

### Como executar o programa
```
time ./nome_arquivo
```

### Como comprovar que os resultados propostos foram alcançados
Serial:
<br/>

<img src="https://github.com/maisafolgueral/grupoA/blob/main/project/print-serial.PNG?raw=true" width="600"/> <br/>

Paralelo:
<br/>

<img src="https://github.com/maisafolgueral/grupoA/blob/main/project/print-paralelo.PNG?raw=true" width="600"/> <br/>

Cálculo Speedup:
```
Speedup = Tempo em 1 CPU / Tempo. em p CPUs
Speedup = 0.001 / 0.001 = 1
```

Número máximo de casa decimais alcançadas:
```
Total = 62
Corretos = 18
```
