clear; clc; close all;

result_array = csvread('results.csv',1,0);

input_size = result_array(:,1)';
brute_time_taken = result_array(:,2)';
brute_num_operations = result_array(:,3)';
select_time_taken = result_array(:,4)';
select_num_operations = result_array(:,5)';

brute_num_operations_expected = (1/2)* ((input_size.^2) - 1);
select_num_operations_expected = 6*(input_size.^1);

line_style_1 = '.b-';
line_style_2 = '.r-';
line_style_expected = 'r';

%% Plot Brute Force Efficiency

% plot the number of operations
figure();
% subplot(2,3,1);
plot(input_size, brute_num_operations, line_style_1);
hold on;
plot(input_size, brute_num_operations_expected, line_style_expected);
title('Brute Force Algorithm - Basic Operations');
xlabel('Input Size (n)');
ylabel('Number of Basic Operations( C(n) )');
legend('Actual','Expected', 'Location', 'NorthWest');
ylim([0 5*10^5])
hold off;

% Plot the time taken
figure();
%subplot(2,3,4);
[hAx,hLine1,hLine2] = plotyy(input_size, brute_num_operations, input_size, brute_time_taken);
hold on;
set(hLine1,'marker','.','linestyle','-','color','b');
set(hLine2,'marker','.','linestyle','-','color','r');
title('Brute Force Algorithm - Time Taken');
xlabel('Input Size (n)');
ylabel(hAx(1),'Number of Basic Operations (C(n))') % left y-axis
ylabel(hAx(2),'Time taken (mS)') % right y-axis
legend('Basic Operations','Time taken', 'Location', 'NorthWest');
hold off;

%% Plot Slection Efficiency

% plot the number of operations
figure();
%subplot(2,3,2);
plot(input_size, select_num_operations, line_style_1);
hold on;
plot(input_size, select_num_operations_expected, line_style_expected);
title('Selection Algorithm - Basic Operations');
xlabel('Input Size (n)');
ylabel('Number of Basic Operations (C(n))');
legend('Actual','Expected', 'Location', 'NorthWest');
hold off;

% Plot the time taken
figure();
%subplot(2,3,5);
[hAx,hLine1,hLine2] = plotyy(input_size, select_num_operations, input_size, select_time_taken);
hold on;
set(hLine1,'marker','.','linestyle','-','color','b');
set(hLine2,'marker','.','linestyle','-','color','r');
title('Selection Algorithm - Time Taken');
xlabel('Input Size (n)');
ylabel(hAx(1),'Number of Basic Operations (C(n))') % left y-axis
ylabel(hAx(2),'Time taken (mS)') % right y-axis
legend('Basic Operations','Time taken', 'Location', 'NorthWest');
hold off;

%% Direct comparison

% Plot the number of operations
figure();
%subplot(2,3,3);
plot(input_size, brute_num_operations, line_style_1);
hold on;
plot(input_size, select_num_operations, line_style_2);
title('Direct Comparison - Basic Operations');
xlabel('Input Size (n)');
ylabel('Number of Basic Operations( C(n) )');
legend('Brute Force','Selection', 'Location', 'NorthWest');
hold off;

% Plot the number of operations
figure();
%subplot(2,3,6);
plot(input_size, brute_time_taken, line_style_1);
hold on;
plot(input_size, select_time_taken, line_style_2);
title('Direct Comparison - Time Taken');
xlabel('Input Size (n)');
ylabel('Time taken (mS)');
legend('Brute Force','Selection', 'Location', 'NorthWest');
hold off;

percenatge_diff = sum((brute_num_operations-brute_num_operations_expected)./brute_num_operations_expected)/length(brute_num_operations_expected);
