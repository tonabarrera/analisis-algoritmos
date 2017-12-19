% Valores de n
n = [100 1000 5000 10000 50000 100000 200000 400000 600000 800000 1000000 ];
% Asi concatenamos más valores
n = [n 2000000 3000000 4000000 5000000 6000000 7000000 8000000 9000000 10000000];
% Promedios a graficar en el eje y
promedios = [0.0000004411 0.0000005007 0.0000005960 0.0000004888 0.0000008464];
promedios = [promedios 0.0000007272 0.0000010014 0.0000012636 0.0000012398];
promedios = [promedios 0.0000012755 0.0000013947 0.0000015974 0.0000019550];
promedios = [promedios 0.0000020862 0.0000023365 0.0000023007 0.0000025272 0.0000022411];
promedios = [promedios 0.0000025988 0.0000025511];
figure;
% plot(n, promedios, 'LineWidth', 2);
% hold;
plot(n, promedios, '*', 'LineWidth', 2);
hold;
% grid;
% xlabel('n');
% ylabel('Tiempo (s)');
% title('Tiempos promedio para n del árbol binario de búsqueda');

% Polinomio
n2=2;
p2=polyfit(n, promedios, n2);
xi=linspace(100, 10000000, 100);
z2=polyval(p2, xi);
plot(xi, z2, '--');
grid;
xlabel('n');
ylabel('f(n)');
title('Aproximación polinomial');
% 50000000 2.6575e-06 0.0000026875
% 100000000 2.8897e-06 0.0000028897
% 500000000 2.9897e-06 0.0000029897
% 1000000000 3.2219e-06 0.0000032219
% 5000000000 3.3219e-06 0.0000033219
