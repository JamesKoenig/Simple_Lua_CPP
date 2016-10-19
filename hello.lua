print("hello world from ".._VERSION);
-- if the C++ hello program ran us, the test table will be defined
if(test) then 
  for k,v in pairs(test) do
    print("calling "..k.." from the C++ code I'm extending")
    print(v())
  end
end

print("opening the dumper module")
ok, err = pcall(function () 
  dump = require("dumper")
  dump.dump("hello world, I'm the dumper function")
  dump.dump("so I'm calling a C++ extension from in lua, which is extending C++")
  dump.dump("here's a number:",6.3, "here's a bool:", true)
  dump.dump("k leavin dumper")
end)
if not ok then --"if not ok then" is my favorite line of this program
  print("couldn't find the dumper module ;_;")
  print("re-raising the error")
  error(err)
end
