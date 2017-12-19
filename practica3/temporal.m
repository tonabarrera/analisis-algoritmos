%x = [728 1340 14548 27308 341634 6213103 50508622];
x = [433 706 14533 27243 340895 6098984 50256396];
y = [0.0094749928 0.0125579834 0.1553800106 0.1730871201 0.8643288612 11.0158841610 100.3086550236];

n2=1;
p2=polyfit(x,y,n2);

xi=linspace(100, 51000000, 100);
z2=polyval(p2, xi);

figure(1);
grid;
plot(x, y, 'ko');
hold on
plot(xi, z2, '--');
hold off
grid;
ylabel('TIEMPO REAL');
xlabel('BYTES');
title('Aproximacion polinomial de grado 1 de la descompresion');