function p = predict(Theta1, Theta2, X)
%PREDICT Predict the label of an input given a trained neural network
%   p = PREDICT(Theta1, Theta2, X) outputs the predicted label of X given the
%   trained weights of a neural network (Theta1, Theta2)

% Useful values
m = size(X, 1);
num_labels = size(Theta2, 1);

% You need to return the following variables correctly 
p = zeros(size(X, 1), 1);

% ====================== YOUR CODE HERE ======================
% Instructions: Complete the following code to make predictions using
%               your learned neural network. You should set p to a 
%               vector containing labels between 1 to num_labels.
%
% Hint: The max function might come in useful. In particular, the max
%       function can also return the index of the max element, for more
%       information see 'help max'. If your examples are in rows, then, you
%       can use max(A, [], 2) to obtain the max for each row.
%
X = [ones(size(X)(1), 1) X];

hiddenLayer = sigmoid(X * Theta1');
hiddenLayer = [ones(size(hiddenLayer)(1),1) hiddenLayer];

output = sigmoid(hiddenLayer * Theta2');

maxMat = max(output, [], 2)==output;

for j=1:size(p)
	for i=1:num_labels
		if(maxMat(j,i)== 1)
			p(j)=i;
		endif
	endfor
endfor
size(p)
% =========================================================================
end
