x = [728 1340 14548 27308 341634];
x_com = [433 706 14533 27243 340895];
y = zeros(1,5);
for i = 1:5
    y(i) = 100-(x_com(i)/x(i))*100;
end;
disp(y);

figure(1);
grid;
plot(x, y, '--', 'LineWidth', 2);
grid;
ylabel('Porcentaje');
xlabel('BYTES');
title('Porcentaje de compresion para distintos archivos');