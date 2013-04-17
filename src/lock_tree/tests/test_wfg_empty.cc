/* -*- mode: C++; c-basic-offset: 4; indent-tabs-mode: nil -*- */
// vim: ft=cpp:expandtab:ts=8:sw=4:softtabstop=4:
#ident "$Id$"
#ident "Copyright (c) 2007-2012 Tokutek Inc.  All rights reserved."
#ident "The technology is licensed by the Massachusetts Institute of Technology, Rutgers State University of New Jersey, and the Research Foundation of State University of New York at Stony Brook under United States of America Serial No. 11/760379 and to the patents and/or patent applications resulting from it."
// find no cycles in an empty WFG

#include "test.h"
#include "wfg.h"

int main(int argc, const char *argv[]) {

    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-v") == 0 || strcmp(argv[i], "--verbose") == 0) {
            verbose++;
            continue;
        }
        if (strcmp(argv[i], "-q") == 0 || strcmp(argv[i], "--quiet") == 0) {
            if (verbose > 0) verbose--;
            continue;
        }
        assert(0);
    }

    // setup
    struct wfg *wfg = wfg_new();
    struct wfg *cycles = wfg_new();

    assert(!wfg_exist_cycle_from_txnid(wfg, 0)); assert(wfg_find_cycles_from_txnid(wfg, 0, cycles) == 0);
    if (verbose) {
        wfg_print(wfg); wfg_print(cycles);
    }
    assert(!wfg_exist_cycle_from_txnid(wfg, 1)); assert(wfg_find_cycles_from_txnid(wfg, 1, cycles) == 0);
    if (verbose) {
        wfg_print(wfg); wfg_print(cycles);
    }

    wfg_free(wfg);
    wfg_free(cycles);

    return 0;
}