# Projeto Tartaruga

|NOME                           |TIA                 |
|-------------------------------|--------------------|
|Filipe Costa Pereira           |32106521            |
|Maisa Folgueral                |32121385            |
|Raphael Vinicius Costa Alencar |32195451            |

<br/>

### Como instalar a biblioteca utilizada<br/>
```
sudo apt-get install libmpfr-dev
```

<br/>

### Como compilar o programa na plataforma disponibilizada
Serial:
```
gcc nome_arquivo.c -o nome_arquivo -lm -lgmp
```
Paralelo:
```
gcc nome_arquivo.c -o nome_arquivo -fopenmp -lm -lgmp
```

<br/>

### Como executar o programa
```
time ./nome_arquivo
```

<br/>

### Como comprovar que os resultados propostos foram alcançados
Serial:
<br/>

<img src="https://github.com/maisafolgueral/grupoA/blob/main/project/img/20230528190100-serial.png?raw=true" width="600"/> <br/>
Resultado do Cálculo: https://github.com/maisafolgueral/grupoA/blob/main/project/output-serial.txt

Paralelo:
<br/>

<img src="https://github.com/maisafolgueral/grupoA/blob/main/project/img/202305291749-paralelo.png?raw=true" width="600"/> <br/>
Resultado do Cálculo: https://github.com/maisafolgueral/grupoA/blob/main/project/output-paralelo.txt

Cálculo Speedup:
```
Speedup = Tempo em 1 CPU / Tempo. em p CPUs
Speedup = 17426.055 / 15840.690 ≈ 1.100
```

Número máximo de casa decimais alcançadas:
```
Total = 3000000
Corretas = 1512857
```

<br/>

### Decomposição de tarefas
1. Quais são as tarefas no caminho crítico para cada grafo de dependência? Para responder a pergunta, apresente um DAG do seu projeto.
```
As tarefas no caminho crítico são: T1, T2, T3, T4, T5, T6 e T7. Isto pode ser visualizado no DAG abaixo:
```
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

<br/>

### Notas importantes
- Inicialmente, estávamos utilizando bibliotecas e tipos de dados nativos da linguagem C. No entanto, não era possível ultrapassar 18 casas decimais corretas. Por isso optamos por utilizar uma biblioteca específica para cálculos com números maiores, nesse caso a biblioteca GMP.
- Para verificar a corretude dos dígitos (casas decimais), utilizamos como referência uma sequência contendo 2 milhões de dígitos disponível no site da NASA. Esta sequência está disponível em: https://apod.nasa.gov/htmltest/gifcity/e.2mil
- Além de executar os programas em CPU, também tentamos a adaptação de nosso código para executar em GPU com o uso de CUDA. No entanto, não obtivemos sucesso, uma vez que surgiram diversos problemas de compatibilidade com a biblioteca GMP. Procuramos por soluções, porém o problema vai além da execução, estando relacionado à aplicação da biblioteca em processamentos por GPU.
