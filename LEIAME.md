# ESP32-Real-Time-Seismic-Data
Simulação de transmissão, recepção e pré-processamento de dados sísmicos em tempo real, utilizando dois microcontroladores ESP32 conectados via comunicação serial.

[Read me in English](README.md)

## Objetivo
Reproduzir o funcionamento de uma Estação Sismológica Remota (ESR) enviando dados para um Centro de Processamento Geofísico (CPG), incluindo mecanismos de verificação de integridade, protocolos de confirmação/reenvio e visualização em tempo real no terminal serial.

## Processamento em Tempo Real de Dados Sísmicos
O Centro Global de Pesquisa Geofísica opera uma rede de Estações Sismológicas Remotas (ESR) em locais tectonicamente ativos. Essas estações monitoram continuamente a atividade sísmica, capturando padrões de vibração como sequências de dados brutos (representados por strings binárias de 8 bits).

Esses dados vitais são transmitidos via um link seguro com comunicação serial para o Centro de Processamento Geofísico (CPG), onde precisam ser rapidamente convertidos para um formato numérico e ser visualizado no terminal serial do computador, para análise imediata por sismólogos que tentam prever eventos ou entender melhor a dinâmica terrestre.

A transmissão e o processamento precisam ser eficientes e robustos. Pela importância da aplicação, cada recebimento no CPG deve informar a ESR a chegada com sucesso dos dados (ou não). Como é de conhecimento geral, a comunicação serial pode sofrer com alteração de algum bit durante a transmissão. É necessário um protocolo para detecção de erro de transmissão (paridade por exemplo) e um pedido de reenvio em caso de falha.

## Arquitetura do Sistema
### ESR (Estação Sismológica Remota – ESP32 #1)
- Gera dados sísmicos simulados como sequências binárias de 7 bits + 1 bit de paridade.
- Transmite os dados ao CPG via serial (1 dado por segundo).
- Exibe logs no monitor serial:
    - Data/hora do envio.
    - Dado transmitido (separando o bit de paridade).
    - Confirmação de recebimento ou solicitação de reenvio.
### CPG (Centro de Processamento Geofísico – ESP32 #2)
- Recebe os dados do ESR.
- Valida integridade usando o bit de paridade.
- Em caso de erro (simulação: 1 a cada 20 transmissões), solicita reenvio.
- Quando válido, confirma o recebimento e converte os 7 bits em inteiro, exibindo no monitor serial.

## Fluxo de Operação
1. ESR gera uma sequência aleatória de 7 bits.
2. O 8º bit (paridade) é adicionado.
3. O dado é transmitido ao CPG.
4. O CPG valida a integridade do dado:
    - Se íntegro → confirma recebimento e converte para inteiro.
    - Se corrompido → solicita reenvio ao ESR.
5. O ESR reenvia o dado até que o CPG o receba corretamente.

## Funcionalidades
- [ ] Comunicação serial robusta entre dois ESP32.
- [ ] Geração de dados binários com bit de paridade.
- [ ] Simulação de falhas de transmissão (~5%).
- [ ] Protocolo de detecção e correção (reenvio).
- [ ] Logs detalhados em ambos os terminais seriais.
- [ ] Conversão automática do dado recebido em valor numérico para análise imediata.