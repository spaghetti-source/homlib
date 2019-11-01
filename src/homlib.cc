#include <boost/python.hpp>

#include "hom.hh"

BOOST_PYTHON_MODULE(homlib) {
  using namespace boost::python;

  class_<Graph>("Graph", init<int>())
    .def("addEdge", &Graph::addEdge);

  def("hom", &hom<double>);
  def("homint", &hom<long long>);

  /*
  class_<VTree>("VTree", init<int>())
    .def("set_root", &VTree::set_root)
    .def("set_child", &VTree::set_child)
    .def("show", &VTree::show);
    */

  //class_<SDD>("SDD", init<VTree>());
}
