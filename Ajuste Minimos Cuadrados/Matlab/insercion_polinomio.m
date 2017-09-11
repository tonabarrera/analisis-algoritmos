%%VALORES DE X
x = [100 1000 5000 10000 50000 100000 200000 400000 600000 800000 1000000];
x(end+1) = 2000000;
x(end+1) = 3000000;
x(end+1) = 4000000;
x(end+1) = 5000000;
% x(end+1) = 6000000;
% x(end+1) = 7000000;
% x(end+1) = 8000000;
% x(end+1) = 9000000;
% x(end+1) = 10000000;

%%VALORES DE Y = F(x)
y = [0.0000209808 0.0017130375 0.0412471294 0.1692869663 4.1332819462];
y(end+1) = 16.4475960732;
y(end+1) = 65.5468389988;
y(end+1) = 261.2090749741;
y(end+1) = 589.3372621536;
y(end+1) = 1050.3749279976;
y(end+1) = 1640.7051041126;
y(end+1) = 6597.4897418022;
y(end+1) = 14811.8683209419;
y(end+1) = 26344.4980440140;
y(end+1) = 41202.4161620140;
% y(end+1) = 6.9999759197;
% y(end+1) = 8.3014740944;
% y(end+1) = 9.8869040012;
% y(end+1) = 10.9567329884;
% y(end+1) = 13.2638001442;

%%OBTENER UN POLINOMIO QUE SE AJUSTE A LOS PUNTOS X Y Y
n1=1;
p1=polyfit(x, y, n1);

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
xi=linspace(100, 5000000, 100);
z1=polyval(p1, xi);
z2=polyval(p2, xi);
z3=polyval(p3, xi);
z4=polyval(p4, xi);
z8=polyval(p8, xi);

%%SE REALIZA LA FIGURA CORRESPONDIENTE
figure(1);
grid;
plot(x, y, 'ko');
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
title('Polinomios para el ordenamiento inserción');