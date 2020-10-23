
x = [-1, 0, 1, 2, 3, 5, 7,15, 20, 100, 409, 500, 593, 1000, 1471, 1500, 2801, 3000, 5000, 10000, 20000]
odds = [0,2,20,100,500,1000,1500,3000,5000,10000,20000]
evens = [-1,1,3,5,7,15,409,593,1471,2801]

odd = (ceil(log2(odds/2))-2).*(floor((odds/2)))
even = (ceil(log2(evens/2))-2).*(floor((evens/2)+1))    

% fprintf("ODDS\n")
% fprintf('[%d] -> %d\n', odd, odds)
% fprintf("EVENS\n")
% fprintf('[%d] -> %d\n', even, evens)

hold on
test = plot(odds, odd)
test.Marker = 'o'
test.Color = 'b'
ylabel('f(n)');
xlabel('x');

second = plot(evens, even)
second.Marker = 'o'
second.Color = 'b'
hold off