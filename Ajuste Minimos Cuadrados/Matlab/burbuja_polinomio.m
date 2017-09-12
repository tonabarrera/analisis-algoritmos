%%VALORES DE X
x = [100 1000 5000 10000 50000 100000 200000 400000 600000 800000 1000000];

%%VALORES DE Y = F(x)
real = [0.0000939369 0.0084688663 0.2341020107 0.8947482109 24.2576978207];
real(end+1) = 97.6079449654;
real(end+1) = 391.7894010544;
real(end+1) = 1577.0236639977;
real(end+1) = 3560.8748540878;
real(end+1) = 6336.6857509613;
real(end+1) = 9893.6090807915;

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
xi=linspace(100, 2000000, 100);
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
grid;
ylabel('F(Y)');
xlabel('X');
legend('Tiempos', 'Grado 1', 'Grado 2', 'Grado 3', 'Grado 4', 'Grado 8');
title('Polinomios para el ordenamiento burbuja');