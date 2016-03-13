function [J grad] = nnCostFunction(nn_params, ...
                                   input_layer_size, ...
                                   hidden_layer_size, ...
                                   num_labels, ...
                                   X, y, lambda)
%NNCOSTFUNCTION Implements the neural network cost function for a two layer
%neural network which performs classification
%   [J grad] = NNCOSTFUNCTON(nn_params, hidden_layer_size, num_labels, ...
%   X, y, lambda) computes the cost and gradient of the neural network. The
%   parameters for the neural network are "unrolled" into the vector
%   nn_params and need to be converted back into the weight matrices. 
% 
%   The returned parameter grad should be a "unrolled" vector of the
%   partial derivatives of the neural network.
%
Theta1 = reshape(nn_params(1:hidden_layer_size * (input_layer_size + 1)), ...
                 hidden_layer_size, (input_layer_size + 1));

Theta2 = reshape(nn_params((1 + (hidden_layer_size * (input_layer_size + 1))):end), ...
                 num_labels, (hidden_layer_size + 1));

% Setup some useful variables
m = size(X, 1);
         
% You need to return the following variables correctly 
J = 0;
Theta1_grad = zeros(size(Theta1));
Theta2_grad = zeros(size(Theta2));

a1 = X;
a1 = [ones(size(a1)(1),1) a1];

z2 = a1 * Theta1';
a2 = sigmoid(z2);
a2 = [ones(size(a2)(1),1) a2];

z3 = a2 * Theta2';
a3 = sigmoid(z3);

h = a3;

yVectorized = zeros(size(y), num_labels);
for i = 1:size(y)
	for j = 1:num_labels
		if (y(i)==j)
			yVectorized(i, j)=1;
		endif
	endfor
endfor

% size(y)
size(yVectorized);
size(h);

J= (sum (sum ( -yVectorized .* log(h) - (1 - yVectorized).*log(1-h)   )))/m;

regTheta1 = Theta1;
regTheta2 = Theta2;

regTheta1(:,1) = 0;
regTheta2(:,1) = 0;

JRegularizationTerm = (lambda/(2*m)) * (sum( sum( regTheta1.*regTheta1)) + sum( sum( regTheta2.*regTheta2)));
J = J + JRegularizationTerm;

del_1=0;
del_2=0;

for t =1:m
	
	a1 = X(t,:);
	a1 = [1 a1];

	z2 = a1 * Theta1';
	a2 = sigmoid(z2);
	a2 = [1 a2];

	z3 = a2 * Theta2';
	a3 = sigmoid(z3);

	h = a3;

	delta3 = a3 - yVectorized(t,:);
	delta2 = (delta3 * Theta2) .* sigmoidGradient([1 z2]);

	del_2 += delta3' * a2;
	del_1 += delta2(2:end)' * a1;

endfor

regularizationFactor1 = (lambda/m ) * regTheta1;
regularizationFactor2 = (lambda/m ) * regTheta2;

Theta1_grad = (del_1/m) + regularizationFactor1;
Theta2_grad = (del_2/m) + regularizationFactor2;

% Unroll gradients
grad = [Theta1_grad(:) ; Theta2_grad(:)];


end
