# ruuvi.libraries.c {#mainpage}
Libraries to be run on embedded devices.

[![Build Status](https://travis-ci.org/ruuvi/ruuvi.libraries.c.svg?branch=master)](https://travis-ci.org/ruuvi/ruuvi.libraries.c)
[![Quality Gate Status](https://sonarcloud.io/api/project_badges/measure?project=ruuvi_ruuvi.libraries.c&metric=alert_status)](https://sonarcloud.io/dashboard?id=ruuvi_ruuvi.libraries.c)
[![Bugs](https://sonarcloud.io/api/project_badges/measure?project=ruuvi_ruuvi.libraries.c&metric=bugs)](https://sonarcloud.io/dashboard?id=ruuvi_ruuvi.libraries.c)
[![Code Smells](https://sonarcloud.io/api/project_badges/measure?project=ruuvi_ruuvi.libraries.c&metric=code_smells)](https://sonarcloud.io/dashboard?id=ruuvi_ruuvi.libraries.c)
[![Coverage](https://sonarcloud.io/api/project_badges/measure?project=ruuvi_ruuvi.libraries.c&metric=coverage)](https://sonarcloud.io/dashboard?id=ruuvi_ruuvi.libraries.c)
[![Duplicated Lines (%)](https://sonarcloud.io/api/project_badges/measure?project=ruuvi_ruuvi.libraries.c&metric=duplicated_lines_density)](https://sonarcloud.io/dashboard?id=ruuvi_ruuvi.libraries.c)
[![Lines of Code](https://sonarcloud.io/api/project_badges/measure?project=ruuvi_ruuvi.libraries.c&metric=ncloc)](https://sonarcloud.io/dashboard?id=ruuvi_ruuvi.libraries.c)
[![Maintainability Rating](https://sonarcloud.io/api/project_badges/measure?project=ruuvi_ruuvi.libraries.c&metric=sqale_rating)](https://sonarcloud.io/dashboard?id=ruuvi_ruuvi.libraries.c)
[![Reliability Rating](https://sonarcloud.io/api/project_badges/measure?project=ruuvi_ruuvi.libraries.c&metric=reliability_rating)](https://sonarcloud.io/dashboard?id=ruuvi_ruuvi.libraries.c)
[![Technical Debt](https://sonarcloud.io/api/project_badges/measure?project=ruuvi_ruuvi.libraries.c&metric=sqale_index)](https://sonarcloud.io/dashboard?id=ruuvi_ruuvi.libraries.c)

# Developing
## Unit testing
Unit tests are run by Ceedling.

## Static code analysis
Test coverage and code analysis are reported by [Sonarcloud](https://sonarcloud.io/dashboard?id=ruuvi.libraries.c). Additionally the project is analyzed with PVS Studio and report is published to [Analysis](https://ruuvi.github.io/ruuvi.libraries.c/fullhtml)

## Styling
Styling is done via Artisitic Style, following configuration at .astylerc. 

## Documentation
[Documentation](https://ruuvi.github.io/ruuvi.libraries.c/) is autogenerated by Doxygen.

## Licenses
 * Unless otherwise stated, code is BSD-3, please see [LICENSE](./LICENSE) for details.

# Changelog
## 3.0.0
 Publish as stable

## 0.2.0
 - Add liblzf compression

## 0.1.4
 - Support Ceedling
 - Support Astyle, check Astyle in GitHub Actions
 - Support SonarCloud, code coverage analysis
 - Support Doxygen
 - Support PVS Studio

## 0.1.3
 - rename semver string to RUUVI_LIBRARIES_SEMVER

## 0.1.2
 - Add conditional compiling to library tests

## 0.1.1
 - Fix semver string

## 0.1.0
 - Add semver
 - Add ceedling structure