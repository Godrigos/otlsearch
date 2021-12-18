#ifndef __OTLSEARCH__
#define __OTLSEARCH__

#include <iostream>
#include <nlohmann/json.hpp>
#include <string>
#include <vector>

using json = nlohmann::json;

class Taxon {
public:
  bool is_synonym;
  std::string search;
  int ottID;
  float score;
  std::string name;
  std::string rank;
  std::vector<std::string> synonyms;
  std::vector<std::string> sources;

  std::string topSearch() {
    this->search[0] = toupper(search[0]);

    return this->search;
  }
};

Taxon search(std::string taxon);
std::string links(std::string source);

std::string const APIURL = "https://api.opentreeoflife.org/v3";
std::string const msg =
    "Open Tree of Life constructs a comprehensive, dynamic and digitally\n"
    "available tree of life by synthesizing published phylogenetic trees\n"
    "along with taxonomic data. https://tree.opentreeoflife.org";

#endif