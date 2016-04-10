function [C, sigma] = dataset3Params(X, y, Xval, yval)
%EX6PARAMS returns your choice of C and sigma for Part 3 of the exercise
%where you select the optimal (C, sigma) learning parameters to use for SVM
%with RBF kernel
%   [C, sigma] = EX6PARAMS(X, y, Xval, yval) returns your choice of C and 
%   sigma. You should complete this function to return the optimal C and 
%   sigma based on a cross-validation set.
%

% You need to return the following variables correctly.
C = 1;
sigma = 0.1;

% ====================== YOUR CODE HERE ======================
% Instructions: Fill in this function to return the optimal C and sigma
%               learning parameters found using the cross validation set.
%               You can use svmPredict to predict the labels on the cross
%               validation set. For example, 
%                   predictions = svmPredict(model, Xval);
%               will return the predictions on the cross validation set.
%
%  Note: You can compute the prediction error using 
%        mean(double(predictions ~= yval))
% %
% values = [0.01, 0.03, 0.1, 0.3, 1, 3, 10, 30]';
% size(values)

% err = zeros(8,8);

% for cIndex = 1:size(values)
% 	for sigmaIndex = 1:size(values)
% 		cI=values(cIndex)
% 		sigmaI=values(sigmaIndex)
% 		modelI= svmTrain(X, y, cI, @(x1, x2) gaussianKernel(x1, x2, sigmaI));
% 		predictions = svmPredict(modelI, Xval);
% 		errorVal = mean(double(predictions ~= yval));
% 		err(cIndex,sigmaIndex) = errorVal;
% 	endfor
% endfor
% err
% % =========================================================================

% minErr = min(min(err));
% [Cind, sigInd]=find(minErr==err);
% C = values(Cind)
% sigma = values(sigInd)


end
