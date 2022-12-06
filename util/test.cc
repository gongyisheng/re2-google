// Copyright 2009 The RE2 Authors.  All Rights Reserved.
// Use of this source code is governed by a BSD-style
// license that can be found in the LICENSE file.

#include <stdio.h>
#include <string>
#include <iostream>

#include "test.h"

namespace testing {
std::string TempDir() { return "/tmp/"; }
}  // namespace testing

struct Test {
  void (*fn)(void); // function pointer
  const char *name; // name of test
};

static Test tests[10000];
static int ntests;

void RegisterTest(void (*fn)(void), const char *name) {
  tests[ntests].fn = fn;
  tests[ntests++].name = name;
}

int main(int argc, char** argv) {
  std::cout << "ntests = " << ntests << std::endl;
  for (int i = 0; i < ntests; i++) {
    printf("%s\n", tests[i].name);
    tests[i].fn();
  }
  printf("PASS\n");
  return 0;
}
