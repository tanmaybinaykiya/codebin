X = [ones(20,1) (exp(1) * sin(1:1:20))' (exp(0.5) * cos(1:1:20))'];
y = sin(X(:,1) + X(:,2)) > 0;
theta = [0.25 0.5 -0.5]';
lambda =  0.1;

for i = 1:45
  [J, grad] = lrCostFunction(theta, X, y, lambda);
  theta = theta - grad;
  J;
endfor

theta
X*theta - y