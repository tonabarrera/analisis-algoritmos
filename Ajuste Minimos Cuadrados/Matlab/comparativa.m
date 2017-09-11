xburbuja = [100 1000 5000 10000 50000 100000 200000 400000 600000 800000 1000000];
xmejorada = [100 1000 5000 10000 50000 100000 200000 400000 600000 800000];
xseleccion = xburbuja;
xseleccion(end+1) = 2000000;
xinsercion = xseleccion;
%xinsercion(end+1) = 3000000;
% xinsercion(end+1) = 4000000;
% xinsercion(end+1) = 5000000;
% xarbol = xinsercion;
% xarbol(end+1) = 6000000;
% xarbol(end+1) = 7000000;
% xarbol(end+1) = 8000000;
% xarbol(end+1) = 9000000;
% xarbol(end+1) = 10000000;

% BURBUJA
burbuja = [0.0000939369 0.0084688663 0.2341020107 0.8947482109 24.2576978207];
burbuja(end+1) = 97.6079449654;
burbuja(end+1) = 391.7894010544;
burbuja(end+1) = 1577.0236639977;
burbuja(end+1) = 3560.8748540878;
burbuja(end+1) = 6336.6857509613;
burbuja(end+1) = 9893.6090807915;

% BURBUJA MEJORADA
mejorada = [0.0000641346 0.0051491261 0.1479711533 0.6746628284 18.2339680195];
mejorada(end+1) = 73.8399429321;
mejorada(end+1) = 296.9164779186;
mejorada(end+1) = 1208.3362858295;
mejorada(end+1) = 2718.3018000126;
mejorada(end+1) = 4758.9755980968;

% SELECCION
seleccion = [0.0000500679 0.0035521984 0.0676710606 0.2772631645 6.6501269341];
seleccion(end+1) = 26.6595389843;
seleccion(end+1) = 106.5870330334;
seleccion(end+1) = 431.8155429363;
seleccion(end+1) = 980.6647109985;
seleccion(end+1) = 1751.5630450249;
seleccion(end+1) = 2743.7960259914;
seleccion(end+1) = 11008.6946151257;

% ARBOL
arbol=[0.0000269413 0.0003678799 0.0023651123 0.0053241253 0.0361769199 0.0872058868 0.2215819359 0.5087170601 0.8277299404];
arbol(end+1) = 1.1993579865;
arbol(end+1) = 1.5597610474;
arbol(end+1) = 3.5892899036;
% arbol(end+1) = 5.7833809853;
% arbol(end+1) = 8.1534841061;
% arbol(end+1) = 10.6610221863;
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
% shell(end+1) = 3.1293799877;
% shell(end+1) = 4.3800368309;
% shell(end+1) = 5.7958707809;
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
% insercion(end+1) = 14811.8683209419;
% insercion(end+1) = 26344.4980440140;
% insercion(end+1) = 41202.4161620140;

%%SE REALIZA LA FIGURA CORRESPONDIENTE
figure(1);
grid;
plot(xinsercion, arbol, '*', 'LineWidth', 2);
hold on
plot(xinsercion, shell, '--', 'LineWidth', 2);
plot(xinsercion, insercion, '--', 'LineWidth', 2);
plot(xseleccion, seleccion, '--', 'LineWidth', 2);
plot(xburbuja, burbuja, '--', 'LineWidth', 2);
plot(xmejorada, mejorada, '--', 'LineWidth', 2);
hold off
grid;
ylabel('TIEMPO(SEG)');
xlabel('TAMAÑO DEL PROBLEMA(N)');
legend('Arbol', 'Shell', 'Insercion', 'Selección', 'Burbuja', 'Burbuja Mejorada');
title('Comparativa de los 6 algoritmos');