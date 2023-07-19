x = 0.01:0.01:10;
xlabel ("x");
ylabel ("f (x)");
function res = f (x);
  res = sin(x)+x;
endfunction

plot(x,f (x));
axis([-10 15 -10 15], "equal");

a = 1
b = a + 0+0.01

function res = inner(p,q,a,b)
  res = quad(@(x) p(x).*q(x), a, b);
endfunction  

function A = create_matrix(f,n,a)
   b = a + 0.01
   
   for i = 1:n
      for j = 1:n
        A(i,j) = quad(@(x) (x-a).^(i+j-2),a,b);
      endfor
   endfor

endfunction

function v = create_vector(f, n, a)
  b = a + 0.01

   for i = 1:n
     v(i) = inner(@f, @(x) (x-a)^(i-1), a, b); 
   endfor

endfunction

n = 8

Maintrix = create_matrix(@f, n, a);
Maintor = create_vector(@f, n, a);

sol = Maintrix\Maintor';  

for i = 1:n
  sol(i) = sol(i)*factorial(i-1);
endfor
  
integ = quadv(@f,a,b)
