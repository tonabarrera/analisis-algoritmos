% Valores de n
n = [100 1000 5000 10000 50000 100000 200000 400000 600000 800000 1000000];
% Asi concatenamos más valores
n = [n 2000000 3000000 4000000 5000000 6000000 7000000 8000000 9000000 10000000];
% Promedios a graficar en el eje y
lineal = [0.000001049060 0.000005912805 0.000026500200 0.000052332860 0.000240647795];
lineal = [lineal 0.000455284125 0.000880062575 0.001743805410 0.002610135080];
lineal = [lineal 0.0034727334955 0.004344248765 0.008610463135 0.012944626805];
lineal = [lineal 0.017202758795 0.021516227715 0.026046550265 0.029794847970 0.033484733120];
lineal = [lineal 0.037549078465 0.040485548980];
figure;
%plot(n, promedios, 'LineWidth', 2);  % Lineas
% hold; % Para poder graficar más elementos
plot(n, promedios, '*', 'LineWidth', 2); % Puntos
hold;
% grid;
% xlabel('n');
% ylabel('Tiempo (s)');
% title('Tiempos promedio para n de la busqueda lineal'); % Titulo

% Polinomio
n2=1;
p2=polyfit(n, promedios, n2);
xi=linspace(100, 10000000, 100);
z2=polyval(p2, xi);
plot(xi, z2, '--');
grid;
xlabel('n');
ylabel('f(n)');
title('Aproximaci�n polinomial');
