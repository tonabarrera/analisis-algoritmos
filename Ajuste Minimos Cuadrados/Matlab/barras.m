prices = [24.0226960182 23.7440000000; 13.2638001442 13.2400000000; 41.2024161620140 41.1731560000000];
bar(prices);
set(gca,'xticklabel',{'Árbol','Shell','Inserción (aprox.)'});
legend('Tiempo Real','Tiempo de CPU');
grid;