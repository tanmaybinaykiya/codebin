function [J, grad] = costFunction(theta, X, y)
	% disp('----------------------costFunction----------------------');
	% disp('theta'), disp(theta);
	m = length(y); % number of training examples

	% You need to return the following variables correctly 
	% J = 0;
	grad = zeros(size(theta));

	h = sigmoid(X*theta);
	computedCost = -((1 .- y) .* log(1 .- h) + (y).*(log(h)));
	J = (sum(computedCost))/m;
	grad = (X'*(h-y))/m;
end
