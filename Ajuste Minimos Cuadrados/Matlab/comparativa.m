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

% ARBOL
arbol=[0.0000269413 0.0003678799 0.0023651123 0.0053241253 0.0361769199 0.0872058868 0.2215819359 0.5087170601 0.8277299404];
arbol(end+1) = 1.1993579865;
arbol(end+1) = 1.5597610474;
arbol(end+1) = 3.5892899036;
arbol(end+1) = 5.7833809853;
arbol(end+1) = 8.1534841061;
arbol(end+1) = 10.6610221863;
% arbol(end+1) = 14.1554899216;
% arbol(end+1) = 16.1131310463;
% arbol(end+1) = 18.4779610634;
% arbol(end+1) = 21.2817759514;
% arbol(end+1) = 24.0226960182;
% SHELL
shell = [0.0000178814 0.0002818108 0.0019121170 0.0043318272 0.0279190540];
shell(end+1) = 0.0635950565;
shell(end+1) = 0.1373591423;
shell(end+1) = 0.3119938374;
shell(end+1) = 0.4762778282;
shell(end+1) = 0.7137169838;
shell(end+1) = 0.8467450142;
shell(end+1) = 1.9436099529;
shell(end+1) = 3.1293799877;
shell(end+1) = 4.3800368309;
shell(end+1) = 5.7958707809;
% shell(end+1) = 6.9999759197;
% shell(end+1) = 8.3014740944;
% shell(end+1) = 9.8869040012;
% shell(end+1) = 10.9567329884;
% shell(end+1) = 13.2638001442;
% INSERCION
insercion = [0.0000209808 0.0017130375 0.0412471294 0.1692869663 4.1332819462];
insercion(end+1) = 16.4475960732;
insercion(end+1) = 65.5468389988;
insercion(end+1) = 261.2090749741;
insercion(end+1) = 589.3372621536;
insercion(end+1) = 1050.3749279976;
insercion(end+1) = 1640.7051041126;
insercion(end+1) = 6597.4897418022;
insercion(end+1) = 14811.8683209419;
insercion(end+1) = 26344.4980440140;
insercion(end+1) = 41202.4161620140;

%%SE REALIZA LA FIGURA CORRESPONDIENTE
figure(1);
grid;
plot(x, arbol, 'o');
hold on
plot(x, shell, '.');
plot(x, insercion, '-');
%plot(x, seleccion, '--');
%plot(x, burbuja, '*');
%plot(x, mejorada, '>');
hold off
ylabel('TIEMPO(SEG)');
xlabel('TAMAÑO DEL PROBLEMA(N)');
legend('Arbol', 'Shell', 'Insercion', 'Selección', 'Burbuja', 'Burbuja Mejorada');
title('Comparativa de los 6 algoritmos');