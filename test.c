#if 1 //output_thefrist
 int border_x[2] = { 4310, 9700 };
 int border_y[2] = { 5370, 9460 };
 int border_z[2] = { 380, 1750 };
#endif
 int range = 10;
 int x_num = (border_x[1] - border_x[0]) / range + 1; // 540
 int y_num = (border_y[1] - border_y[0]) / range + 1;
 int z_num = (border_z[1] - border_z[0]) / range + 1;

 laplacian ob;
 ob.xvec = { { { 0,-1,0 },{ -1,-2,-1 },{ 0,-1,0 } } ,{ { 0,0,0 },{ 0,0,0 },{ 0,0,0 } },{ { 0,1,0 },{ 1,2,1 },{ 0,1,0 } } };
 ob.yvec = { { { 0,-1,0 },{ 0,0,0 },{ 0,1,0 } } ,{ { -1,-2,-1 },{ 0,0,0 },{ 1,2,1 } },{ { 0,-1,0 },{ 0,0,0 },{ 0,1,0 } } };
 ob.zvec = { { { 0,0,0 },{ -1,0,1 },{ 0,0,0 } } ,{ { -1,0,-1 },{ -2,0,2 },{ -1,0,1 } },{ { 0,0,0 },{ -1,0,1 },{ 0,0,0 } } };
 string Valuepath1 = "F:\\start\\1_jinchuan\\task4_sobel\\sobel\\input\\Cu_2.txt";
 vector<double>ValueInit;
 ReadValue(Valuepath1, ValueInit);
 int position;
 vector<double>GradIfunVec2(3);
 vector<vector<double>>GradIfunVec1(3, GradIfunVec2);
 vector<vector<vector<double>>> ValueNearVec(3, GradIfunVec1);

 ofstream dataFile;
 dataFile.open("F:\\start\\1_jinchuan\\task4_sobel\\sobel\\output\\Cu_2.txt", ios::app); //shuchu
 if (!dataFile.is_open())
 {
  cout << "False" << endl;
  return 0;
 }

 for (int i = 0; i < x_num; i++)
  for (int j = 0; j < y_num; j++)
   for (int k = 0; k < z_num; k++)
   {
    if ((i != 0) && (i != x_num - 1) && (j != 0) && (j != y_num - 1) && (k != 0) && (k != z_num - 1))
    {
     double pt1 = 0.0;
     double pt2 = 0.0;
     double pt3 = 0.0;
     Point3D InPoint(border_x[0]+i*range, border_y[0] + j*range, border_z[0] + k*range);
     for (int a = 0; a <= 2; a++)
     {
      for (int b = 0; b <= 2; b++)
      {
       for (int c = 0; c <= 2; c++)
       {
        DPoint3 NewPt;
        NewPt.x = InPoint.GetX() + (a-1) * range;
        NewPt.y = InPoint.GetY() + (b-1) * range;
        NewPt.z = InPoint.GetZ() + (c-1) * range;
        position = (NewPt.x - border_x[0]) / range * z_num * y_num + (NewPt.y - border_y[0]) / range * z_num + (NewPt.z - border_z[0]) / range;
				pt1 += ValueInit[position] * ob.xvec[a][b][c];
        pt2 += ValueInit[position] * ob.yvec[a][b][c];
        pt3 += ValueInit[position] * ob.zvec[a][b][c];
       }
      }
      //cout << icount << endl;
     }
     dataFile << fixed << setprecision(14) << pt1 << "," << pt2 << "," << pt3 << endl;
     //gradVec.push_back(pt);
    }
   }
 dataFile.close();
 system("pause");
 return 0;
}
#endif