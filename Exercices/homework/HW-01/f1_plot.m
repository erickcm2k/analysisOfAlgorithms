
x = [-1, 0, 1, 2, 3, 5, 15, 20, 100, 409, 500, 593, 1000, 1471, 1500, 2801, 3000, 5000, 10000, 20000]
y = log2(x/2)
%fprintf('%f\n', y)


test = plot(x,y)
test.Marker = 'o'
test.Color = 'b'
ylabel('f(n)');
xlabel('x');