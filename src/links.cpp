#include "otlsearch.hpp"

std::string links(std::string source) {

  std::string link;

  if (source.substr(0, source.find(":")) == "ncbi") {
    link = "www.ncbi.nlm.nih.gov/Taxonomy/Browser/wwwtax.cgi?id=" +
           source.substr(source.find(":") + 1, source.length());
  } else if (source.substr(0, source.find(":")) == "gbif") {
    link = "www.gbif.org/species/" +
           source.substr(source.find(":") + 1, source.length());
  } else if (source.substr(0, source.find(":")) == "irmng") {
    link = "www.irmng.org/aphia.php?p=taxdetails&id=" +
           source.substr(source.find(":") + 1, source.length());
  } else if (source.substr(0, source.find(":")) == "worms") {
    link = "www.marinespecies.org/aphia.php?p=taxdetails&id=" +
           source.substr(source.find(":") + 1, source.length());
  } else if (source.substr(0, source.find(":")) == "if") {
    link = "www.indexfungorum.org/names/NamesRecord.asp?RecordID=" +
           source.substr(source.find(":") + 1, source.length());
  } else if (source.substr(0, source.find(":")) == "silva") {
    link = "www.arb-silva.de/browser/ssu/silva/" +
           source.substr(source.find(":") + 1, source.length());
  } else {
    link = source;
  }

  return link;
}