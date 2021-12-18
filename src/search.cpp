#include "otlsearch.hpp"
#include <cpr/cpr.h>

Taxon search(std::string name) {

  std::string searchList = "{\"names\":[\"" + name + "\"]}";

  cpr::Response r = cpr::Post(
      cpr::Url{APIURL + "/tnrs/match_names"}, cpr::Body{searchList},
      cpr::Header{{"Content-Type", "application/json"}}, cpr::Timeout{10000});

  if (r.status_code != 200) {
    std::cout << "Error while trying to search for taxon." << std::endl;
    exit(EXIT_FAILURE);
  } else if (json::parse(r.text)["results"][0]["matches"].empty()) {
    std::cout << "No matches found." << std::endl;
    exit(EXIT_FAILURE);
  }

  Taxon taxon{
      json::parse(r.text)["results"][0]["matches"][0]["is_synonym"],
      json::parse(r.text)["results"][0]["matches"][0]["search_string"],
      json::parse(r.text)["results"][0]["matches"][0]["taxon"]["ott_id"],
      json::parse(r.text)["results"][0]["matches"][0]["score"],
      json::parse(r.text)["results"][0]["matches"][0]["taxon"]["name"],
      json::parse(r.text)["results"][0]["matches"][0]["taxon"]["rank"],
      json::parse(r.text)["results"][0]["matches"][0]["taxon"]["synonyms"],
      json::parse(r.text)["results"][0]["matches"][0]["taxon"]["tax_sources"],
  };

  return taxon;
}