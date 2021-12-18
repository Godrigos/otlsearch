#include "otlsearch.hpp"

int main(int argc, char const *argv[]) {

  if (argc != 2) {
    std::cerr << "Usage: " << argv[0] << " \"taxon name\"." << std::endl;
    exit(EXIT_FAILURE);
  }

  Taxon taxon = search(argv[1]);

  std::cout << msg << "\n";

  std::cout << "\n" << std::string(80, '-') << "\n";

  std::cout << "* Search:\t" << taxon.topSearch() << "\t|\t* Synonym:\t";
  if (taxon.is_synonym) {
    std::cout << "Yes";
  } else {
    std::cout << "No";
  };

  std::cout << "\n" << std::string(80, '-') << "\n";

  std::cout << "* Taxon:\t" << taxon.name << "\n";

  std::cout << "* Rank:\t\t" << taxon.rank << "\n";
  std::cout << "* Score:\t" << std::fixed << std::setprecision(1) << taxon.score
            << "\n";
  std::cout << "* Ott:\t\t"
            << "https://tree.opentreeoflife.org/taxonomy/browse?id="
            << taxon.ottID << "\n";
  std::cout << "* Newick:\t"
            << "https://tree.opentreeoflife.org/opentree/default/"
               "download_subtree/ottol-id/"
            << taxon.ottID << std::endl;

  std::cout << std::string(80, '-') << "\n";
  std::cout << "* Sources:\n";
  for (std::string const &i : taxon.sources) {
    std::cout << "\t" << links(i) << "\n";
  }

  std::cout << std::string(80, '-') << "\n";
  std::cout << "* Synonyms:\n";
  for (std::string const &i : taxon.synonyms) {
    std::cout << "\t" << i << "\n";
  }
  std::cout << std::string(80, '-') << "\n";

  std::cout << std::endl;

  links("if:345");

  return EXIT_SUCCESS;
}