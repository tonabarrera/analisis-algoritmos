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

% TIEMPO REAL
real = [0.0000178814 0.0002818108 0.0019121170 0.0043318272 0.0279190540];
real(end+1) = 0.0635950565;
real(end+1) = 0.1373591423;
real(end+1) = 0.3119938374;
real(end+1) = 0.4762778282;
real(end+1) = 0.7137169838;
real(end+1) = 0.8467450142;
real(end+1) = 1.9436099529;
real(end+1) = 3.1293799877;
real(end+1) = 4.3800368309;
real(end+1) = 5.7958707809;
real(end+1) = 6.9999759197;
real(end+1) = 8.3014740944;
real(end+1) = 9.8869040012;
real(end+1) = 10.9567329884;
real(end+1) = 13.2638001442;
% TIEMPO CPU
CPU = [0.0000000000 0.0000000000 0.0040000000 0.0040000000 0.0280000000];
CPU(end+1) = 0.0640000000;
CPU(end+1) = 0.1400000000;
CPU(end+1) = 0.3120000000;
CPU(end+1) = 0.4760000000;
CPU(end+1) = 0.6920000000;
CPU(end+1) = 0.8440000000;
CPU(end+1) = 1.9320000000;
CPU(end+1) = 3.1280000000;
CPU(end+1) = 4.3240000000;
CPU(end+1) = 5.7720000000;
CPU(end+1) = 6.9920000000;
CPU(end+1) = 8.2960000000;
CPU(end+1) = 9.8800000000;
CPU(end+1) = 10.9440000000;
CPU(end+1) = 13.2400000000;

% TIEMPO E/S
ES = [0.0000000000 0.0000000000 0.0000000000 0.0000000000 0.0000000000];
ES(end+1) = 0.0000000000;
ES(end+1) = 0.0000000000;
ES(end+1) = 0.0000000000;
ES(end+1) = 0.0000000000;
ES(end+1) = 0.0000000000;
ES(end+1) = 0.0000000000;
ES(end+1) = 0.0000000000;
ES(end+1) = 0.0000000000;
ES(end+1) = 0.0040000000;
ES(end+1) = 0.0200000000;
ES(end+1) = 0.0000000000;
ES(end+1) = 0.0000000000;
ES(end+1) = 0.0040000000;
ES(end+1) = 0.0040000000;
ES(end+1) = 0.0080000000;
%%SE REALIZA LA FIGURA CORRESPONDIENTE
figure(1);
grid;
plot(x, real, 'o', 'LineWidth', 2);
hold on
plot(x, CPU, '--', 'LineWidth', 2);
plot(x, ES, '-', 'LineWidth', 2);
hold off
grid;
ylabel('TIEMPO(SEG)');
xlabel('TAMAÑO DEL PROBLEMA(N)');
legend('Tiempo real', 'Tiempo de CPU', 'Tiempo de E/S');
title('Tiempos del ordenamiento shell');