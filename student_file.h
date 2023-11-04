vector<int> Torneo(vector<int> vec, int N, int K) 
{
  int ganador = 0;
  int regGanador = 0;
  int perdedor= 0;

  if (vec.size() >= 2) {
    for (int i = 1; i <= K; i++) {
      int elemento1 = vec[0]; 
      int elemento2 = vec[1];

      if(ganador == N){
          // Mueve el ganador actual al final del vector
          perdedor = elemento2;
          vec.push_back(elemento1);       


          // Desplaza los demás elementos una posición hacia adelante
          for (int j = 0; j < vec.size() - 1; j++) {
            vec[j] = vec[j + 1];
          }     

          ganador = 0;
          vec.pop_back();
          //Anulamos este "juego"
          i--;

        }
      else{
      if (elemento1 > elemento2) {

        // Desplaza los demás elementos una posición hacia adelante
        perdedor = elemento2;
        vec.push_back(elemento2);
        for (int j = 1; j < vec.size() - 1; j++) {
          vec[j] = vec[j + 1];
        }

        if (regGanador == elemento1){
          ganador++;
        }
        else {
          regGanador = elemento1;
          ganador = 1; // Cambia el ganador
        }       

        vec.pop_back();
      }

        else{
          // Desplaza los demás elementos
          perdedor = elemento1;
          
          vec.push_back(elemento1);
          for (int j = 0; j < vec.size() - 1; j++) {
            vec[j] = vec[j + 1];
          }

          if (regGanador == elemento2){
            ganador++;
          }
          else {
            regGanador = elemento2;
            ganador = 1; // Cambia el ganador
          }
          vec.pop_back();
        }

      }
    }
    // Asignacion de vector
    vector <int> L_W= {perdedor, regGanador};

    for (int i = 0; i < L_W.size(); i++) {
      cout << L_W[i] << " ";
    }
    cout << endl;
  } else {
    cout << "El vector no tiene al menos dos elementos." << endl;
  }

  return vec;
}
