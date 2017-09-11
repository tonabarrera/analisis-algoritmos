%%VALORES DE X
% x=[1.425 1.39 1.32 1.235 1.205 1.105 1.05 0.9 0.84 0.74];
x = [100 1000 5000 10000 50000 100000 200000 400000 600000 800000 1000000];
x(end+1) = 2000000;
x(end+1) = 3000000;
x(end+1) = 4000000;
x(end+1) = 5000000;
x(end+1) = 6000000;
x(end+1) = 7000000;
x(end+1) = 8000000;
x(end+1) = 9000000;
x(end+1) = 10000000;

%%VALORES DE Y = F(x)
% y = [1 2 3 4 5 6 7 8 9 10 11];
y=[0.0000269413 0.0003678799 0.0023651123 0.0053241253 0.0361769199 0.0872058868 0.2215819359 0.5087170601 0.8277299404];
y(end+1) = 1.1993579865;
y(end+1) = 1.5597610474;
y(end+1) = 3.5892899036;
y(end+1) = 5.7833809853;
y(end+1) = 8.1534841061;
y(end+1) = 10.6610221863;
y(end+1) = 14.1554899216;
y(end+1) = 16.1131310463;
y(end+1) = 18.4779610634;
y(end+1) = 21.2817759514;
y(end+1) = 24.0226960182;
%disp(y);
%%OBTENER UN POLINOMIO QUE SE AJUSTE A LOS PUNTOS X Y Y
n1=1; 				%%GRADO DEL POLINOMIO DE AJUSTE
p1=polyfit(x, y, n1);	%%FUNCION QUE REALIZA EL AJUSTE POLINOMIAL

n2=2;
p2=polyfit(x,y,n2);

n3=3;
p3=polyfit(x,y,n3);

n4=4;
p4=polyfit(x,y,n4);

n8=8;
p8=polyfit(x,y,n8);

%%SE CREA UN ESPACIO PARA REALIZAR UNA GRAFICA EN 
%%DONDE SE COMPARA LA CURVA AJUSTADA CONTRA LOS 
%%VALORES EXPERIMENTALES
xi=linspace(100, 10000000, 100);	%%ESPACIO DE PUNTOS PARA Xi
z1=polyval(p1, xi);				%%EVALUACION DEL POLINOMIO P EN EL ESPACIO Xi
z2=polyval(p2, xi);
z3=polyval(p3, xi);
z4=polyval(p4, xi);
z8=polyval(p8, xi);

%%SE REALIZA LA FIGURA CORRESPONDIENTE
figure(1);
grid;
plot(x, y, 'ko');
hold on
plot(xi, z1, '--');
plot(xi, z2, '--');
plot(xi, z3, '--');
plot(xi, z4, '--');
plot(xi, z8, '--');
hold off
ylabel('F(Y)');
xlabel('X');
legend('Tiempos', 'Grado 1', 'Grado 2', 'Grado 3', 'Grado 4', 'Grado 8');
title('Polinomios para el ordenamiento de árbol');
