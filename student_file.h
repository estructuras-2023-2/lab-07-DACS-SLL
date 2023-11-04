vector<int> Torneo(vector<int> vec, int N, int K) 
{
  int ganador = 0;
  int regGanador = 0;

  if (vec.size() >= 2) {
    for (int i = 0; i < K; i++) {
      int elemento1 = vec[0]; 
      int elemento2 = vec[1];

      if (ganador == N){
        // Mueve el ganador actual al final del vector
        vec.push_back(elemento1);

        // Desplaza los demás elementos una posición hacia adelante
        for (int j = 0; j < vec.size() - 1; j++) {
          vec[j] = vec[j + 1];
        }     

        vec.pop_back();
        ganador = 0;
      } else {
        if (elemento1 > elemento2) {
          // Desplaza los demás elementos una posición hacia adelante
          vec.push_back(elemento2);
          for (int j = 1; j < vec.size() - 1; j++) {
            vec[j] = vec[j + 1];
          }

          if (regGanador == elemento1){
            ganador++;
          } else {
            regGanador = elemento1;
            ganador = 1; // Reinicia la cuenta cuando cambia el ganador
          }       

          vec.pop_back();
        } else {
          // Desplaza los demás elementos una posición hacia adelante
          vec.push_back(elemento1);
          for (int j = 0; j < vec.size() - 1; j++) {
            vec[j] = vec[j + 1];
          }

          if (regGanador == elemento2){
            ganador++;
          } else {
            regGanador = elemento2;
            ganador = 1; // Reinicia la cuenta cuando cambia el ganador
          }
          vec.pop_back();
        }
      }

      // Realiza operaciones con elemento1 y elemento2 según sea necesario
      for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
      }
      cout << endl;
      cout << "Elemento 1: " << elemento1 << endl;
      cout << "Elemento 2: " << elemento2 << endl;
      cout << "Ganador: " << regGanador << endl; 
      cout << "Veces: " << ganador << endl; 
    }
  } else {
    cout << "El vector no tiene al menos dos elementos." << endl;
  }

  return vec;
}
