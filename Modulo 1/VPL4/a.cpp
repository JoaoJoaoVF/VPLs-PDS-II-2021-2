Nave *Nave::determinar_nave_mais_proxima(Nave **naves, int n)
{
    Nave a;
    //for (int i = 0; i < n; i++)
    // {
    //    double DX = naves[i]->x - x;
    //   double DY = naves[i]->y - y;
    //   double a = sqrt(DX * DX + DY * DY);
    //}
    double dist = 0, dist2 = -99;
    int num_nave = 0;
    for (int i = 0; i < n; i++)
    {
        dist = a.calcular_distancia(naves[i]);
        if (dist2 == -99)
        {
            dist2 = dist;
        }
        if (dist < dist2)
        {
            dist2 = dist;
            num_nave = i;
        }
    }
    //cout << "distancia euclidiana " << dist << endl;
    //}
    //int i = num_nave;
    // cout << "numero da nave retornada nessa funcao"<<i<<endl;
    return naves[num_nave];
    //return naves[0];
}