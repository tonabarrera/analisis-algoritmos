%%VALORES DE X
x = [100 1000 5000 10000 50000 100000 200000 400000 600000 800000 1000000];
x(end+1) = 2000000;

%%VALORES DE Y = F(x)
real = [0.0000500679 0.0035521984 0.0676710606 0.2772631645 6.6501269341];
real(end+1) = 26.6595389843;
real(end+1) = 106.5870330334;
real(end+1) = 431.8155429363;
real(end+1) = 980.6647109985;
real(end+1) = 1751.5630450249;
real(end+1) = 2743.7960259914;
real(end+1) = 11008.6946151257;

%%OBTENER UN POLINOMIO QUE SE AJUSTE A LOS PUNTOS X Y Y
n1=1;
p1=polyfit(x, real, n1);

n2=2;
p2=polyfit(x, real, n2);

n3=3;
p3=polyfit(x, real, n3);

n4=4;
p4=polyfit(x, real, n4);

n8=8;
p8=polyfit(x, real, n8);

%%SE CREA UN ESPACIO PARA REALIZAR UNA GRAFICA EN 
%%DONDE SE COMPARA LA CURVA AJUSTADA CONTRA LOS 
%%VALORES EXPERIMENTALES
xi=linspace(100, 2400000, 100);
z1=polyval(p1, xi);
z2=polyval(p2, xi);
z3=polyval(p3, xi);
z4=polyval(p4, xi);
z8=polyval(p8, xi);

%%SE REALIZA LA FIGURA CORRESPONDIENTE
figure(1);
grid;
plot(x, real, 'ko', 'LineWidth', 2);
hold on
plot(xi, z1, '--', 'LineWidth', 2);
plot(xi, z2, '--', 'LineWidth', 2);
plot(xi, z3, '--', 'LineWidth', 2);
plot(xi, z4, '--', 'LineWidth', 2);
plot(xi, z8, '--', 'LineWidth', 2);
hold off
ylabel('F(Y)');
xlabel('X');
legend('Tiempos', 'Grado 1', 'Grado 2', 'Grado 3', 'Grado 4', 'Grado 8');
title('Polinomios para el ordenamiento de selección');