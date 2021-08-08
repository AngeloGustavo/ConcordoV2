#include <iostream>
#include <list>
#include <vector>
#include <string>
#include "sistema.h"
#include "executor.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int main() {
  // inicialização do sistema
  Sistema sistema;
  Executor executor(sistema);

  mkdir("../data/canais_servidores",0777);
  sistema.load_user();
  sistema.load_server();
  // o executor recebe o cin e o cout. Ele os utilizará para ler as linhas
  // de comando, executar o método correto em "sistema" e exibir as mensagens
  executor.iniciar(cin, cout);

  return 0;
}
