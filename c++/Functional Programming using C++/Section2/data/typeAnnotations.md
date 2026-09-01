int x;
x : Int

std::vector<int> xs;
xs : [Int]

std:map<Key, Value>dict;
dict : Map Key Value

int foo(string);
foo : String -> Int

ContainerIn transform(F f, const ContainerOut& xs);
transform : ((a -> b), [a]) -> [b]
the function transform takes two parameters.
the first one is a function taking an a and returning a b.
the second one is a sequence of elements of type a.
Finally transform returns a sequence of elements of type b.

vector<U> transform(std::function<U(T)>, vector<T>);

keep_if : ((a -> Bool), [a]) -> [a]
the function keep_if takes two parameters.
the first one is a function taking an a and returning bool.
the seconds one is a sequence of elements of type a.
Finally keep_if returns a sequence of elements of type a.

keep_if : ((Float -> Bool), [Float]) -> [Float]

class lentil {
// ...
};

std::vector<lentil> lentils;

bool is_good_one(const lentil&);
const auto pot = keep_if(is_good_one, lentils);

[[a]] -> [a] // flatten out map
foo(["bar", "baz", "buz"], ";") == "bar;baz;buz"
(vector<string>, string) -> string

join : ([char], [[char]]) -> [char]
join : ([a], [[a]]) -> [a]
