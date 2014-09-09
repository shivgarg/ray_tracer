struct vector3d{
    double x,y,z;
};


vector3d cross_prod(vector3d u,vector3d v)
{
    vector3d a;
    a.x=u.y*v.z-u.z*v.y;
    a.y=u.z*v.x-u.x*v.z;
    a.z=u.x*v.y-v.x*u.y;
    return a;
}

vector3d norm(vector3d c)
{
    vector3d p;
    double a=sqrt(c.x*c.x+c.y*c.y+c.z*c.z);
    p.x=c.x/a;p.y=c.y/a;p.z=c.z/a;
    return p;
}

vector3d scalarmulti(double x,vector3d y)
{
    vector3d o;
    o.x=x*y.x;
    o.y=x*y.y;
    o.z=x*y.z;
    return o;
}

vector3d subvec(vector3d a,vector3d b)
{
    vector3d g;
    g.x=a.x-b.x;
    g.y=a.y-b.y;
    g.z=a.z-b.z;
    return g;
}
vector3d addvec(vector3d a,vector3d b)
{
    vector3d g;
    g.x=a.x+b.x;
    g.y=a.y+b.y;
    g.z=a.z+b.z;
    return g;
}
double dot(vector3d a,vector3d b)
{
  return a.x*b.x+a.y*b.y+a.z*b.z;
}
