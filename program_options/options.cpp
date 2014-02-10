//
// Using Boost program options
//   style:   ./options [options] <required arg>
//   example: ./options --x=3 filename
//

#include <iostream>
#include <string>
#include <boost/program_options.hpp>

using namespace std;
using namespace boost::program_options;

int main(int argc, char* argv[])
{
  //
  // command-line options (Boost program_options)
  //
  options_description opt("options [options] filename");
  opt.add_options()
    ("help,h", "display this help")
    ("filename,f", value<string>(), "filename")
    ("n", value<int>()->default_value(128), "integer n")
    ("x", value<double>()->default_value(1.0, "1"), "real number x")
    ;
  
  positional_options_description p;
  p.add("filename", -1);
  
  variables_map vm;
  store(command_line_parser(argc, argv).options(opt).positional(p).run(), vm);
  notify(vm);

  if(vm.count("help") || ! vm.count("filename")) {
    cout << opt; 
    return 0;
  }

  const int n= vm["n"].as<int>(); assert(n > 0);
  cout << "n= " << n << endl;

  const double x= vm["x"].as<double>();
  cout << "x= " << x << endl;

  const string filename= vm["filename"].as<string>();
  cout << "filename= " << filename << endl;

  return 0;
}
