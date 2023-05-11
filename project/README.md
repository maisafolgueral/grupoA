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

<img src="https://github.com/maisafolgueral/grupoA/blob/main/project/img/202305260000-serial.PNG?raw=true" width="600"/> <br/>

Paralelo:
<br/>

<img src="https://github.com/maisafolgueral/grupoA/blob/main/project/img/202305060000-paralelo.PNG?raw=true" width="600"/> <br/>

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

### Decomposição de tarefas
1. Quais são as tarefas no caminho crítico para cada grafo de dependência? Para responder a pergunta, apresente um DAG do seu projeto.

<img src="https://github.com/maisafolgueral/grupoA/blob/main/project/img/202305110046-dag.PNG?raw=true" height="700"/> <br/>

2. Qual é o limite inferior do tempo de execução paralela para cada decomposição?
```
O limite inferior é calculado utilizando: tempo para executar em P workers (processadores); 
tempo para a execução serial (em 1 worker); tempo para percorrer o caminho crítico.
```
<img src="https://github.com/maisafolgueral/grupoA/blob/main/project/img/202305110147-formula.png?raw=true" width="600"/> <br/>

3. Quantos processadores são necessários para se conseguir o tempo mínimo de execução?
```
Quanto mais processadores utilizados para o processamento, menor tende a ser o tempo de execução. 
Assim, o programa deve tirar o máximo proveito de todos os processadores disponíveis.
```
4. Qual é o grau máximo de concorrência?
```
O grau máximo de concorrência é igual ao número máximo de tarefas concorrentes em qualquer ponto da execução. 
Em nosso programa, as tarefas concorrentes são executadas através de threads. 
Portanto, com 2 threads o grau máximo de concorrência é 2.
```
5. Qual é o paralelismo médio?
```
Para calcularmos o paralelismo médio, levamos em consideração o total de trabalho e o comprimento de caminho crítico. 
Em nosso programa, conforme apresentado no DAG, a razão do total de trabalho (10) para o comprimento de caminho crítico (7),
isto é, o paralelismo médio equivale a 1,43. Considere, para todos os exemplos, que todas as tarefas consomem uma unidade de 
tempo para execução.
```
