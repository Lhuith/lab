#!/bin/bash

kubectl patch crd alertmanagerconfigs.monitoring.coreos.com -p '{"metadata":{"finalizers":[]}}' --type=merge
kubectl patch crd alertmanagers.monitoring.coreos.com -p '{"metadata":{"finalizers":[]}}' --type=merge
kubectl patch crd podmonitors.monitoring.coreos.com -p '{"metadata":{"finalizers":[]}}' --type=merge
kubectl patch crd probes.monitoring.coreos.com -p '{"metadata":{"finalizers":[]}}' --type=merge
kubectl patch crd prometheusagents.monitoring.coreos.com -p '{"metadata":{"finalizers":[]}}' --type=merge
kubectl patch crd prometheuses.monitoring.coreos.com -p '{"metadata":{"finalizers":[]}}' --type=merge
kubectl patch crd prometheusrules.monitoring.coreos.com -p '{"metadata":{"finalizers":[]}}' --type=merge
kubectl patch crd scrapeconfigs.monitoring.coreos.com -p '{"metadata":{"finalizers":[]}}' --type=merge
kubectl patch crd servicemonitors.monitoring.coreos.com -p '{"metadata":{"finalizers":[]}}' --type=merge
kubectl patch crd thanosrulers.monitoring.coreos.com -p '{"metadata":{"finalizers":[]}}' --type=merge
