function g = sigmoid(z)
%SIGMOID Compute sigmoid functoon

	% disp('dim(size)'), disp(size(z));
	g = (1 + exp(-z)).^-1;
end
