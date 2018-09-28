#include <inttypes.h>

extern uint8_t get_next_bit();

int16_t get_next_symbol() {
  if(get_next_bit() == 1) {
    if(get_next_bit() == 1) {
      if(get_next_bit() == 1) {
        if(get_next_bit() == 1) {
          return -1; // 1111
        } else {
          if(get_next_bit() == 1) {
            if(get_next_bit() == 1) {
              if(get_next_bit() == 1) {
                return -8; // 1110111
              } else {
                if(get_next_bit() == 1) {
                  if(get_next_bit() == 1) {
                    if(get_next_bit() == 1) {
                      return -30; // 1110110111
                    } else {
                      if(get_next_bit() == 1) {
                        return -41; // 11101101101
                      } else {
                        return -45; // 11101101100
                      }
                    }
                  } else {
                    if(get_next_bit() == 1) {
                      if(get_next_bit() == 1) {
                        return 49; // 11101101011
                      } else {
                        return 44; // 11101101010
                      }
                    } else {
                      if(get_next_bit() == 1) {
                        if(get_next_bit() == 1) {
                          if(get_next_bit() == 1) {
                            if(get_next_bit() == 1) {
                              return -86; // 11101101001111
                            } else {
                              return -88; // 11101101001110
                            }
                          } else {
                            if(get_next_bit() == 1) {
                              return 99; // 11101101001101
                            } else {
                              return 96; // 11101101001100
                            }
                          }
                        } else {
                          if(get_next_bit() == 1) {
                            if(get_next_bit() == 1) {
                              return 80; // 11101101001011
                            } else {
                              return 79; // 11101101001010
                            }
                          } else {
                            return -60; // 1110110100100
                          }
                        }
                      } else {
                        if(get_next_bit() == 1) {
                          if(get_next_bit() == 1) {
                            return -72; // 1110110100011
                          } else {
                            return 87; // 1110110100010
                          }
                        } else {
                          if(get_next_bit() == 1) {
                            return 82; // 1110110100001
                          } else {
                            return 78; // 1110110100000
                          }
                        }
                      }
                    }
                  }
                } else {
                  if(get_next_bit() == 1) {
                    return -17; // 111011001
                  } else {
                    return -18; // 111011000
                  }
                }
              }
            } else {
              if(get_next_bit() == 1) {
                if(get_next_bit() == 1) {
                  if(get_next_bit() == 1) {
                    if(get_next_bit() == 1) {
                      if(get_next_bit() == 1) {
                        if(get_next_bit() == 1) {
                          if(get_next_bit() == 1) {
                            return 73; // 1110101111111
                          } else {
                            return 69; // 1110101111110
                          }
                        } else {
                          return -64; // 111010111110
                        }
                      } else {
                        if(get_next_bit() == 1) {
                          return -68; // 111010111101
                        } else {
                          return 57; // 111010111100
                        }
                      }
                    } else {
                      return 30; // 1110101110
                    }
                  } else {
                    if(get_next_bit() == 1) {
                      return 27; // 1110101101
                    } else {
                      return -31; // 1110101100
                    }
                  }
                } else {
                  if(get_next_bit() == 1) {
                    return 19; // 111010101
                  } else {
                    if(get_next_bit() == 1) {
                      if(get_next_bit() == 1) {
                        return 42; // 11101010011
                      } else {
                        if(get_next_bit() == 1) {
                          if(get_next_bit() == 1) {
                            return 63; // 1110101001011
                          } else {
                            return -75; // 1110101001010
                          }
                        } else {
                          return 67; // 111010100100
                        }
                      }
                    } else {
                      return -32; // 1110101000
                    }
                  }
                }
              } else {
                if(get_next_bit() == 1) {
                  return 12; // 11101001
                } else {
                  if(get_next_bit() == 1) {
                    if(get_next_bit() == 1) {
                      if(get_next_bit() == 1) {
                        if(get_next_bit() == 1) {
                          return 65; // 111010001111
                        } else {
                          return 59; // 111010001110
                        }
                      } else {
                        if(get_next_bit() == 1) {
                          return 55; // 111010001101
                        } else {
                          if(get_next_bit() == 1) {
                            return -80; // 1110100011001
                          } else {
                            return -89; // 1110100011000
                          }
                        }
                      }
                    } else {
                      return -29; // 1110100010
                    }
                  } else {
                    return -19; // 111010000
                  }
                }
              }
            }
          } else {
            return 3; // 11100
          }
        }
      } else {
        if(get_next_bit() == 1) {
          return 1; // 1101
        } else {
          if(get_next_bit() == 1) {
            if(get_next_bit() == 1) {
              return -6; // 110011
            } else {
              if(get_next_bit() == 1) {
                if(get_next_bit() == 1) {
                  if(get_next_bit() == 1) {
                    if(get_next_bit() == 1) {
                      return 32; // 1100101111
                    } else {
                      if(get_next_bit() == 1) {
                        if(get_next_bit() == 1) {
                          if(get_next_bit() == 1) {
                            return 76; // 1100101110111
                          } else {
                            return 75; // 1100101110110
                          }
                        } else {
                          return -62; // 110010111010
                        }
                      } else {
                        return -46; // 11001011100
                      }
                    }
                  } else {
                    if(get_next_bit() == 1) {
                      if(get_next_bit() == 1) {
                        return 51; // 11001011011
                      } else {
                        return 43; // 11001011010
                      }
                    } else {
                      return 31; // 1100101100
                    }
                  }
                } else {
                  return 13; // 11001010
                }
              } else {
                if(get_next_bit() == 1) {
                  if(get_next_bit() == 1) {
                    return -20; // 110010011
                  } else {
                    return 20; // 110010010
                  }
                } else {
                  if(get_next_bit() == 1) {
                    return 21; // 110010001
                  } else {
                    if(get_next_bit() == 1) {
                      return -34; // 1100100001
                    } else {
                      if(get_next_bit() == 1) {
                        if(get_next_bit() == 1) {
                          return 71; // 110010000011
                        } else {
                          if(get_next_bit() == 1) {
                            if(get_next_bit() == 1) {
                              if(get_next_bit() == 1) {
                                if(get_next_bit() == 1) {
                                  return -115; // 1100100000101111
                                } else {
                                  return -122; // 1100100000101110
                                }
                              } else {
                                if(get_next_bit() == 1) {
                                  return -125; // 1100100000101101
                                } else {
                                  return -131; // 1100100000101100
                                }
                              }
                            } else {
                              if(get_next_bit() == 1) {
                                if(get_next_bit() == 1) {
                                  return -134; // 1100100000101011
                                } else {
                                  return -137; // 1100100000101010
                                }
                              } else {
                                if(get_next_bit() == 1) {
                                  return -138; // 1100100000101001
                                } else {
                                  return -140; // 1100100000101000
                                }
                              }
                            }
                          } else {
                            if(get_next_bit() == 1) {
                              if(get_next_bit() == 1) {
                                if(get_next_bit() == 1) {
                                  return -142; // 1100100000100111
                                } else {
                                  return -143; // 1100100000100110
                                }
                              } else {
                                if(get_next_bit() == 1) {
                                  return -150; // 1100100000100101
                                } else {
                                  return -161; // 1100100000100100
                                }
                              }
                            } else {
                              if(get_next_bit() == 1) {
                                if(get_next_bit() == 1) {
                                  return -166; // 1100100000100011
                                } else {
                                  return -200; // 1100100000100010
                                }
                              } else {
                                if(get_next_bit() == 1) {
                                  return 180; // 1100100000100001
                                } else {
                                  return 162; // 1100100000100000
                                }
                              }
                            }
                          }
                        }
                      } else {
                        return 47; // 11001000000
                      }
                    }
                  }
                }
              }
            }
          } else {
            if(get_next_bit() == 1) {
              if(get_next_bit() == 1) {
                if(get_next_bit() == 1) {
                  return -12; // 11000111
                } else {
                  return -13; // 11000110
                }
              } else {
                return 9; // 1100010
              }
            } else {
              return 6; // 110000
            }
          }
        }
      }
    } else {
      if(get_next_bit() == 1) {
        if(get_next_bit() == 1) {
          if(get_next_bit() == 1) {
            return -4; // 10111
          } else {
            if(get_next_bit() == 1) {
              if(get_next_bit() == 1) {
                if(get_next_bit() == 1) {
                  if(get_next_bit() == 1) {
                    if(get_next_bit() == 1) {
                      if(get_next_bit() == 1) {
                        return 41; // 10110111111
                      } else {
                        if(get_next_bit() == 1) {
                          if(get_next_bit() == 1) {
                            if(get_next_bit() == 1) {
                              if(get_next_bit() == 1) {
                                if(get_next_bit() == 1) {
                                  return 155; // 1011011111011111
                                } else {
                                  return 154; // 1011011111011110
                                }
                              } else {
                                if(get_next_bit() == 1) {
                                  return 152; // 1011011111011101
                                } else {
                                  return 151; // 1011011111011100
                                }
                              }
                            } else {
                              if(get_next_bit() == 1) {
                                if(get_next_bit() == 1) {
                                  return 148; // 1011011111011011
                                } else {
                                  return 146; // 1011011111011010
                                }
                              } else {
                                if(get_next_bit() == 1) {
                                  return 144; // 1011011111011001
                                } else {
                                  return 142; // 1011011111011000
                                }
                              }
                            }
                          } else {
                            if(get_next_bit() == 1) {
                              if(get_next_bit() == 1) {
                                if(get_next_bit() == 1) {
                                  return 138; // 1011011111010111
                                } else {
                                  return 137; // 1011011111010110
                                }
                              } else {
                                if(get_next_bit() == 1) {
                                  return 136; // 1011011111010101
                                } else {
                                  return 123; // 1011011111010100
                                }
                              }
                            } else {
                              if(get_next_bit() == 1) {
                                if(get_next_bit() == 1) {
                                  return 120; // 1011011111010011
                                } else {
                                  return 119; // 1011011111010010
                                }
                              } else {
                                if(get_next_bit() == 1) {
                                  return 118; // 1011011111010001
                                } else {
                                  return 117; // 1011011111010000
                                }
                              }
                            }
                          }
                        } else {
                          if(get_next_bit() == 1) {
                            if(get_next_bit() == 1) {
                              if(get_next_bit() == 1) {
                                if(get_next_bit() == 1) {
                                  return 115; // 1011011111001111
                                } else {
                                  return 105; // 1011011111001110
                                }
                              } else {
                                return -100; // 101101111100110
                              }
                            } else {
                              if(get_next_bit() == 1) {
                                return -101; // 101101111100101
                              } else {
                                return -111; // 101101111100100
                              }
                            }
                          } else {
                            if(get_next_bit() == 1) {
                              if(get_next_bit() == 1) {
                                return -112; // 101101111100011
                              } else {
                                return -113; // 101101111100010
                              }
                            } else {
                              if(get_next_bit() == 1) {
                                return -114; // 101101111100001
                              } else {
                                return -116; // 101101111100000
                              }
                            }
                          }
                        }
                      }
                    } else {
                      if(get_next_bit() == 1) {
                        if(get_next_bit() == 1) {
                          if(get_next_bit() == 1) {
                            if(get_next_bit() == 1) {
                              if(get_next_bit() == 1) {
                                return -120; // 101101111011111
                              } else {
                                return -128; // 101101111011110
                              }
                            } else {
                              if(get_next_bit() == 1) {
                                return -132; // 101101111011101
                              } else {
                                return -136; // 101101111011100
                              }
                            }
                          } else {
                            if(get_next_bit() == 1) {
                              if(get_next_bit() == 1) {
                                return -139; // 101101111011011
                              } else {
                                return 128; // 101101111011010
                              }
                            } else {
                              if(get_next_bit() == 1) {
                                return 125; // 101101111011001
                              } else {
                                return 122; // 101101111011000
                              }
                            }
                          }
                        } else {
                          if(get_next_bit() == 1) {
                            if(get_next_bit() == 1) {
                              if(get_next_bit() == 1) {
                                return 112; // 101101111010111
                              } else {
                                return 111; // 101101111010110
                              }
                            } else {
                              if(get_next_bit() == 1) {
                                return 109; // 101101111010101
                              } else {
                                return 108; // 101101111010100
                              }
                            }
                          } else {
                            if(get_next_bit() == 1) {
                              if(get_next_bit() == 1) {
                                return 106; // 101101111010011
                              } else {
                                return 103; // 101101111010010
                              }
                            } else {
                              if(get_next_bit() == 1) {
                                return 95; // 101101111010001
                              } else {
                                return 92; // 101101111010000
                              }
                            }
                          }
                        }
                      } else {
                        if(get_next_bit() == 1) {
                          if(get_next_bit() == 1) {
                            if(get_next_bit() == 1) {
                              return -98; // 10110111100111
                            } else {
                              return -99; // 10110111100110
                            }
                          } else {
                            if(get_next_bit() == 1) {
                              return -107; // 10110111100101
                            } else {
                              return -124; // 10110111100100
                            }
                          }
                        } else {
                          if(get_next_bit() == 1) {
                            if(get_next_bit() == 1) {
                              return 113; // 10110111100011
                            } else {
                              return 107; // 10110111100010
                            }
                          } else {
                            return -79; // 1011011110000
                          }
                        }
                      }
                    }
                  } else {
                    if(get_next_bit() == 1) {
                      if(get_next_bit() == 1) {
                        if(get_next_bit() == 1) {
                          if(get_next_bit() == 1) {
                            return -91; // 1011011101111
                          } else {
                            return -94; // 1011011101110
                          }
                        } else {
                          if(get_next_bit() == 1) {
                            return 104; // 1011011101101
                          } else {
                            return 85; // 1011011101100
                          }
                        }
                      } else {
                        if(get_next_bit() == 1) {
                          if(get_next_bit() == 1) {
                            return 83; // 1011011101011
                          } else {
                            return 81; // 1011011101010
                          }
                        } else {
                          return -54; // 101101110100
                        }
                      }
                    } else {
                      if(get_next_bit() == 1) {
                        if(get_next_bit() == 1) {
                          return -63; // 101101110011
                        } else {
                          return -77; // 101101110010
                        }
                      } else {
                        return -48; // 10110111000
                      }
                    }
                  }
                } else {
                  if(get_next_bit() == 1) {
                    return 22; // 101101101
                  } else {
                    if(get_next_bit() == 1) {
                      return 37; // 1011011001
                    } else {
                      return -37; // 1011011000
                    }
                  }
                }
              } else {
                return -9; // 1011010
              }
            } else {
              if(get_next_bit() == 1) {
                if(get_next_bit() == 1) {
                  if(get_next_bit() == 1) {
                    return 24; // 101100111
                  } else {
                    if(get_next_bit() == 1) {
                      if(get_next_bit() == 1) {
                        return 50; // 10110011011
                      } else {
                        if(get_next_bit() == 1) {
                          if(get_next_bit() == 1) {
                            return 66; // 1011001101011
                          } else {
                            if(get_next_bit() == 1) {
                              return 102; // 10110011010101
                            } else {
                              return -87; // 10110011010100
                            }
                          }
                        } else {
                          return -69; // 101100110100
                        }
                      }
                    } else {
                      if(get_next_bit() == 1) {
                        if(get_next_bit() == 1) {
                          return -70; // 101100110011
                        } else {
                          return 62; // 101100110010
                        }
                      } else {
                        return 48; // 10110011000
                      }
                    }
                  }
                } else {
                  return 14; // 10110010
                }
              } else {
                if(get_next_bit() == 1) {
                  return 15; // 10110001
                } else {
                  if(get_next_bit() == 1) {
                    if(get_next_bit() == 1) {
                      return 39; // 1011000011
                    } else {
                      if(get_next_bit() == 1) {
                        return 53; // 10110000101
                      } else {
                        if(get_next_bit() == 1) {
                          if(get_next_bit() == 1) {
                            return -71; // 1011000010011
                          } else {
                            return -73; // 1011000010010
                          }
                        } else {
                          if(get_next_bit() == 1) {
                            return -81; // 1011000010001
                          } else {
                            return -82; // 1011000010000
                          }
                        }
                      }
                    }
                  } else {
                    if(get_next_bit() == 1) {
                      return -36; // 1011000001
                    } else {
                      return 34; // 1011000000
                    }
                  }
                }
              }
            }
          }
        } else {
          if(get_next_bit() == 1) {
            return 4; // 10101
          } else {
            if(get_next_bit() == 1) {
              return -7; // 101001
            } else {
              if(get_next_bit() == 1) {
                return 10; // 1010001
              } else {
                if(get_next_bit() == 1) {
                  if(get_next_bit() == 1) {
                    return -23; // 101000011
                  } else {
                    if(get_next_bit() == 1) {
                      if(get_next_bit() == 1) {
                        if(get_next_bit() == 1) {
                          if(get_next_bit() == 1) {
                            return -84; // 1010000101111
                          } else {
                            return -92; // 1010000101110
                          }
                        } else {
                          if(get_next_bit() == 1) {
                            return -96; // 1010000101101
                          } else {
                            return 100; // 1010000101100
                          }
                        }
                      } else {
                        if(get_next_bit() == 1) {
                          if(get_next_bit() == 1) {
                            return 90; // 1010000101011
                          } else {
                            return 68; // 1010000101010
                          }
                        } else {
                          return -66; // 101000010100
                        }
                      }
                    } else {
                      if(get_next_bit() == 1) {
                        return -52; // 10100001001
                      } else {
                        return -53; // 10100001000
                      }
                    }
                  }
                } else {
                  if(get_next_bit() == 1) {
                    return -21; // 101000001
                  } else {
                    return -22; // 101000000
                  }
                }
              }
            }
          }
        }
      } else {
        if(get_next_bit() == 1) {
          return -2; // 1001
        } else {
          if(get_next_bit() == 1) {
            if(get_next_bit() == 1) {
              if(get_next_bit() == 1) {
                return -10; // 1000111
              } else {
                if(get_next_bit() == 1) {
                  if(get_next_bit() == 1) {
                    return 26; // 100011011
                  } else {
                    if(get_next_bit() == 1) {
                      return -35; // 1000110101
                    } else {
                      return -39; // 1000110100
                    }
                  }
                } else {
                  if(get_next_bit() == 1) {
                    if(get_next_bit() == 1) {
                      return -40; // 1000110011
                    } else {
                      return 35; // 1000110010
                    }
                  } else {
                    return -24; // 100011000
                  }
                }
              }
            } else {
              if(get_next_bit() == 1) {
                if(get_next_bit() == 1) {
                  return 16; // 10001011
                } else {
                  if(get_next_bit() == 1) {
                    if(get_next_bit() == 1) {
                      if(get_next_bit() == 1) {
                        return -56; // 10001010111
                      } else {
                        if(get_next_bit() == 1) {
                          return -58; // 100010101101
                        } else {
                          return -65; // 100010101100
                        }
                      }
                    } else {
                      if(get_next_bit() == 1) {
                        if(get_next_bit() == 1) {
                          return 64; // 100010101011
                        } else {
                          return 58; // 100010101010
                        }
                      } else {
                        return 54; // 10001010100
                      }
                    }
                  } else {
                    if(get_next_bit() == 1) {
                      return 40; // 1000101001
                    } else {
                      return 38; // 1000101000
                    }
                  }
                }
              } else {
                if(get_next_bit() == 1) {
                  return -14; // 10001001
                } else {
                  if(get_next_bit() == 1) {
                    if(get_next_bit() == 1) {
                      return 33; // 1000100011
                    } else {
                      if(get_next_bit() == 1) {
                        return -50; // 10001000101
                      } else {
                        return 61; // 10001000100
                      }
                    }
                  } else {
                    return 23; // 100010000
                  }
                }
              }
            }
          } else {
            if(get_next_bit() == 1) {
              return 7; // 100001
            } else {
              if(get_next_bit() == 1) {
                if(get_next_bit() == 1) {
                  if(get_next_bit() == 1) {
                    if(get_next_bit() == 1) {
                      if(get_next_bit() == 1) {
                        return 60; // 10000011111
                      } else {
                        return 52; // 10000011110
                      }
                    } else {
                      return -38; // 1000001110
                    }
                  } else {
                    if(get_next_bit() == 1) {
                      return -43; // 1000001101
                    } else {
                      return 36; // 1000001100
                    }
                  }
                } else {
                  if(get_next_bit() == 1) {
                    if(get_next_bit() == 1) {
                      if(get_next_bit() == 1) {
                        if(get_next_bit() == 1) {
                          if(get_next_bit() == 1) {
                            if(get_next_bit() == 1) {
                              return -93; // 10000010111111
                            } else {
                              return -95; // 10000010111110
                            }
                          } else {
                            if(get_next_bit() == 1) {
                              return -105; // 10000010111101
                            } else {
                              return -109; // 10000010111100
                            }
                          }
                        } else {
                          if(get_next_bit() == 1) {
                            if(get_next_bit() == 1) {
                              return -110; // 10000010111011
                            } else {
                              return -118; // 10000010111010
                            }
                          } else {
                            if(get_next_bit() == 1) {
                              return -146; // 10000010111001
                            } else {
                              return 130; // 10000010111000
                            }
                          }
                        }
                      } else {
                        if(get_next_bit() == 1) {
                          if(get_next_bit() == 1) {
                            if(get_next_bit() == 1) {
                              return 124; // 10000010110111
                            } else {
                              return 101; // 10000010110110
                            }
                          } else {
                            if(get_next_bit() == 1) {
                              return 98; // 10000010110101
                            } else {
                              return 97; // 10000010110100
                            }
                          }
                        } else {
                          if(get_next_bit() == 1) {
                            if(get_next_bit() == 1) {
                              return 94; // 10000010110011
                            } else {
                              return 91; // 10000010110010
                            }
                          } else {
                            return -90; // 1000001011000
                          }
                        }
                      }
                    } else {
                      if(get_next_bit() == 1) {
                        if(get_next_bit() == 1) {
                          if(get_next_bit() == 1) {
                            return -97; // 1000001010111
                          } else {
                            return -102; // 1000001010110
                          }
                        } else {
                          if(get_next_bit() == 1) {
                            return -103; // 1000001010101
                          } else {
                            return 93; // 1000001010100
                          }
                        }
                      } else {
                        if(get_next_bit() == 1) {
                          if(get_next_bit() == 1) {
                            return 89; // 1000001010011
                          } else {
                            return 88; // 1000001010010
                          }
                        } else {
                          return -61; // 100000101000
                        }
                      }
                    }
                  } else {
                    if(get_next_bit() == 1) {
                      if(get_next_bit() == 1) {
                        if(get_next_bit() == 1) {
                          return -67; // 100000100111
                        } else {
                          return -74; // 100000100110
                        }
                      } else {
                        if(get_next_bit() == 1) {
                          return -76; // 100000100101
                        } else {
                          return 74; // 100000100100
                        }
                      }
                    } else {
                      if(get_next_bit() == 1) {
                        return -47; // 10000010001
                      } else {
                        return -49; // 10000010000
                      }
                    }
                  }
                }
              } else {
                if(get_next_bit() == 1) {
                  return 18; // 10000001
                } else {
                  if(get_next_bit() == 1) {
                    if(get_next_bit() == 1) {
                      return 46; // 1000000011
                    } else {
                      return -44; // 1000000010
                    }
                  } else {
                    return -25; // 100000000
                  }
                }
              }
            }
          }
        }
      }
    }
  } else {
    if(get_next_bit() == 1) {
      return 0; // 01
    } else {
      if(get_next_bit() == 1) {
        if(get_next_bit() == 1) {
          return 2; // 0011
        } else {
          if(get_next_bit() == 1) {
            return -5; // 00101
          } else {
            if(get_next_bit() == 1) {
              if(get_next_bit() == 1) {
                if(get_next_bit() == 1) {
                  if(get_next_bit() == 1) {
                    return -26; // 001001111
                  } else {
                    return -28; // 001001110
                  }
                } else {
                  return 17; // 00100110
                }
              } else {
                return -11; // 0010010
              }
            } else {
              if(get_next_bit() == 1) {
                if(get_next_bit() == 1) {
                  if(get_next_bit() == 1) {
                    return 25; // 001000111
                  } else {
                    return -33; // 001000110
                  }
                } else {
                  if(get_next_bit() == 1) {
                    return 28; // 001000101
                  } else {
                    if(get_next_bit() == 1) {
                      if(get_next_bit() == 1) {
                        return 56; // 00100010011
                      } else {
                        if(get_next_bit() == 1) {
                          if(get_next_bit() == 1) {
                            return 84; // 0010001001011
                          } else {
                            if(get_next_bit() == 1) {
                              return 86; // 00100010010101
                            } else {
                              if(get_next_bit() == 1) {
                                return -104; // 001000100101001
                              } else {
                                return -106; // 001000100101000
                              }
                            }
                          }
                        } else {
                          return -83; // 001000100100
                        }
                      }
                    } else {
                      if(get_next_bit() == 1) {
                        if(get_next_bit() == 1) {
                          return 77; // 001000100011
                        } else {
                          return 72; // 001000100010
                        }
                      } else {
                        return -57; // 00100010000
                      }
                    }
                  }
                }
              } else {
                return 11; // 0010000
              }
            }
          }
        }
      } else {
        if(get_next_bit() == 1) {
          if(get_next_bit() == 1) {
            return 5; // 00011
          } else {
            if(get_next_bit() == 1) {
              if(get_next_bit() == 1) {
                if(get_next_bit() == 1) {
                  return -15; // 00010111
                } else {
                  if(get_next_bit() == 1) {
                    return 29; // 000101101
                  } else {
                    if(get_next_bit() == 1) {
                      if(get_next_bit() == 1) {
                        return -59; // 00010110011
                      } else {
                        if(get_next_bit() == 1) {
                          return 70; // 000101100101
                        } else {
                          if(get_next_bit() == 1) {
                            return -78; // 0001011001001
                          } else {
                            return -85; // 0001011001000
                          }
                        }
                      }
                    } else {
                      return -42; // 0001011000
                    }
                  }
                }
              } else {
                if(get_next_bit() == 1) {
                  return -16; // 00010101
                } else {
                  if(get_next_bit() == 1) {
                    if(get_next_bit() == 1) {
                      return 45; // 0001010011
                    } else {
                      if(get_next_bit() == 1) {
                        return -51; // 00010100101
                      } else {
                        return -55; // 00010100100
                      }
                    }
                  } else {
                    return -27; // 000101000
                  }
                }
              }
            } else {
              return 8; // 000100
            }
          }
        } else {
          return -3; // 0000
        }
      }
    }
  }
}
